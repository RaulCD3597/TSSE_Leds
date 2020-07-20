#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"












uint16_t virtuales;



void setUp(void)

{

    LedsCreate(&virtuales);

}





void test_todos_los_leds_inician_apagados(void)

{

    uint16_t virtuales = 0xFFFF;

    LedsCreate(&virtuales);

    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

}





void test_encender_un_led(void)

{

    LedsTurnOn(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0001)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_y_apagar_un_led(void)

{

    LedsTurnOn(1);

    LedsTurnOff(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_Y_apagar_algunos_leds(void)

{

    LedsTurnOn(3);

    LedsTurnOn(5);

    LedsTurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0010)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_UINT16);

}





void test_asegurarse_que_un_led_no_afecta_los_demas(void)

{

    LedsTurnOn(1);

    LedsTurnOn(3);

    LedsTurnOn(5);

    LedsTurnOn(8);

    LedsTurnOff(3);

    LedsTurnOff(8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0011)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_todos_los_leds_simultaneamente(void)

{

    LedsTurnAllOn();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0xFFFF)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_UINT16);

}





void test_apagar_todos_los_leds_simultaneamente(void)

{

    LedsTurnAllOn();

    LedsTurnAllOff();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_UINT16);

}





void test_consultar_el_estado_de_un_led_prendido(void)

{

    LedsTurnOn(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((1)), (UNITY_INT)(UNITY_UINT8 )((LedsReadState(2))), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_UINT8);

}





void test_consultar_el_estado_de_un_led_apagado(void)

{

    LedsTurnAllOn();

    LedsTurnOff(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((LedsReadState(2))), (

   ((void *)0)

   ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_UINT8);

}
