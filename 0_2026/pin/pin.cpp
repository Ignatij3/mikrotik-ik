#include "pin.hpp"

namespace io
{

void Pin::Init() const
{
    Enable_Clock_(Port_);
    GPIO_InitTypeDef InitStruct_{
        Pin_Pos_,                // pin
        (uint32)Conf_.pinMode,   // mode
        (uint32)Conf_.pinPull,   // pull
        (uint32)Conf_.pinSpeed,  // speed
        (uint32)Conf_.alt        // alternate function
    };
    HAL_GPIO_Init(Port_, &InitStruct_);
}

void Pin::DeInit() const
{
    HAL_GPIO_DeInit(Port_, Pin_Pos_);
    Disable_Clock_(Port_);
}

void Pin::Enable_Clock_(const Port port)
{
    if (port == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();

    } else if (port == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();

    } else if (port == GPIOC) {
        __HAL_RCC_GPIOC_CLK_ENABLE();

#ifdef GPIOD
    } else if (port == GPIOD) {
        __HAL_RCC_GPIOD_CLK_ENABLE();
#endif

#ifdef GPIOE
    } else if (port == GPIOE) {
        __HAL_RCC_GPIOE_CLK_ENABLE();
#endif

#ifdef GPIOF
    } else if (port == GPIOF) {
        __HAL_RCC_GPIOF_CLK_ENABLE();
#endif

#ifdef GPIOG
    } else if (port == GPIOG) {
        __HAL_RCC_GPIOG_CLK_ENABLE();
#endif

    } else if (port == GPIOH) {
        __HAL_RCC_GPIOH_CLK_ENABLE();

#ifdef GPIOI
    } else if (port == GPIOI) {
        __HAL_RCC_GPIOI_CLK_ENABLE();
#endif
    }
}

void Pin::Disable_Clock_(const Port port)
{
    if (port == GPIOA) {
        __HAL_RCC_GPIOA_CLK_DISABLE();

    } else if (port == GPIOB) {
        __HAL_RCC_GPIOB_CLK_DISABLE();

    } else if (port == GPIOC) {
        __HAL_RCC_GPIOC_CLK_DISABLE();

#ifdef GPIOD
    } else if (port == GPIOD) {
        __HAL_RCC_GPIOD_CLK_DISABLE();
#endif

#ifdef GPIOE
    } else if (port == GPIOE) {
        __HAL_RCC_GPIOE_CLK_DISABLE();
#endif

#ifdef GPIOF
    } else if (port == GPIOF) {
        __HAL_RCC_GPIOF_CLK_DISABLE();
#endif

#ifdef GPIOG
    } else if (port == GPIOG) {
        __HAL_RCC_GPIOG_CLK_DISABLE();
#endif

    } else if (port == GPIOH) {
        __HAL_RCC_GPIOH_CLK_DISABLE();

#ifdef GPIOI
    } else if (port == GPIOI) {
        __HAL_RCC_GPIOI_CLK_DISABLE();
#endif
    }
}

}  // namespace io