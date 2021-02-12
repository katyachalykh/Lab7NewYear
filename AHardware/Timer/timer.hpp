#pragma once


class Timer
{
  public:
    void Start(uint32_t Period)
    {
      NVIC::ISER0::Write(1<<28);
      TIM2::CR1::URS::OverflowEvent::Set();
      RCC::APB1ENR::TIM2EN::Enable::Set();
      TIM2::PSC::Set(7999U);
      TIM2::ARR::Write(Period);
      TIM2::SR::UIF::NoInterruptPending::Set();
      TIM2::CNT::Write(0U);
      TIM2::DIER::UIE::Enable::Set();
      TIM2::CR1::CEN::Enable::Set();
      while (!TIM2::SR::UIF::NoInterruptPending::IsSet() )
      {
      }
      
    }
    void ChangePeriod (uint32_t Period)
    {
      TIM2::ARR::Write(Period);
    }
};