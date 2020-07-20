/**
 * consultar el estado de un led apagado
 * Parametros son invalidos
 * Parametro en valores de borde
 */
#include "unity.h"
#include "leds.h"

uint16_t virtuales;

void setUp(void)
{
    LedsCreate(&virtuales);
}

//! @test Todos los leds empiezan apagados
void test_todos_los_leds_inician_apagados(void)
{
    uint16_t virtuales = 0xFFFF;
    LedsCreate(&virtuales);
    TEST_ASSERT_EQUAL(0x0000, virtuales);
}

//! @test Encender un led
void test_encender_un_led(void)
{
    LedsTurnOn(1);
    TEST_ASSERT_EQUAL_UINT16(0x0001, virtuales);
}

//! @test Prender y apagar un led
void test_prender_y_apagar_un_led(void)
{
    LedsTurnOn(1);
    LedsTurnOff(1);
    TEST_ASSERT_EQUAL_UINT16(0x0000, virtuales);
}

//! @test Prender y apagar algunos leds
void test_prender_Y_apagar_algunos_leds(void)
{
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);
    TEST_ASSERT_EQUAL_UINT16(0x0010, virtuales);
}

//! @test Asegurarse que un led no afecta los demas
void test_asegurarse_que_un_led_no_afecta_los_demas(void)
{
    LedsTurnOn(1);
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOn(8);
    LedsTurnOff(3);
    LedsTurnOff(8);
    TEST_ASSERT_EQUAL_UINT16(0x0011, virtuales);
}

//! @test Prender todos los leds simultaneamente
void test_prender_todos_los_leds_simultaneamente(void)
{
    LedsTurnAllOn();
    TEST_ASSERT_EQUAL_UINT16(0xFFFF, virtuales);
}

//! @test Apagar todos los leds simultaneamente
void test_apagar_todos_los_leds_simultaneamente(void)
{
    LedsTurnAllOn();
    LedsTurnAllOff();
    TEST_ASSERT_EQUAL_UINT16(0x0000, virtuales);
}

//! @test Consultar el estado de un led prendido
void test_consultar_el_estado_de_un_led_prendido(void)
{
    LedsTurnOn(2);
    TEST_ASSERT_EQUAL_UINT8(1, LedsReadState(2));
}

//! @test consultar el estado de un led apagado
void test_consultar_el_estado_de_un_led_apagado(void)
{
    LedsTurnAllOn();
    LedsTurnOff(2);
    TEST_ASSERT_EQUAL_UINT8(0, LedsReadState(2));
}