/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
volatile uint8_t ADC_flag=0;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
const uint16_t arr1[2]={0,4095};        //方波
uint8_t arr1_index=0; //指向arr1的第几个元素 索引

static const uint16_t arr2[256] = {                                     //正弦�?
  2048, 2098, 2148, 2198, 2248, 2298, 2348, 2397,
  2447, 2496, 2545, 2594, 2642, 2690, 2737, 2784,
  2831, 2877, 2923, 2968, 3013, 3057, 3100, 3143,
  3185, 3226, 3267, 3307, 3346, 3385, 3423, 3460,
  3496, 3531, 3565, 3599, 3631, 3663, 3693, 3722,
  3750, 3777, 3803, 3828, 3852, 3874, 3895, 3915,
  3934, 3951, 3968, 3982, 3996, 4008, 4019, 4028,
  4036, 4043, 4048, 4052, 4055, 4056, 4056, 4055,
  4052, 4048, 4043, 4036, 4028, 4019, 4008, 3996,
  3982, 3968, 3951, 3934, 3915, 3895, 3874, 3852,
  3828, 3803, 3777, 3750, 3722, 3693, 3663, 3631,
  3599, 3565, 3531, 3496, 3460, 3423, 3385, 3346,
  3307, 3267, 3226, 3185, 3143, 3100, 3057, 3013,
  2968, 2923, 2877, 2831, 2784, 2737, 2690, 2642,
  2594, 2545, 2496, 2447, 2397, 2348, 2298, 2248,
  2198, 2148, 2098, 2048, 1998, 1948, 1898, 1848,
  1798, 1748, 1699, 1649, 1600, 1551, 1502, 1454,
  1406, 1359, 1312, 1265, 1219, 1173, 1128, 1083,
  1039, 996,  953,  911,  870,  829,  789,  750,
  711,  673,  636,  600,  565,  531,  497,  465,
  433,  403,  374,  346,  319,  293,  268,  244,
  222,  201,  181,  162,  145,  128,  113,  100,
   88,   77,   68,   60,   53,   48,   44,   41,
   40,   40,   41,   44,   48,   53,   60,   68,
   77,   88,  100,  113,  128,  145,  162,  181,
  201,  222,  244,  268,  293,  319,  346,  374,
  403,  433,  465,  497,  531,  565,  600,  636,
  673,  711,  750,  789,  829,  870,  911,  953,
  996, 1039, 1083, 1128, 1173, 1219, 1265, 1312,
  1359, 1406, 1454, 1502, 1551, 1600, 1649, 1699,
  1748, 1798, 1848, 1898, 1948, 1998
};
uint8_t arr2_index=0; //指向arr2的第几个元素 索引


static const uint16_t arr3[256] = {
    0,   32,   64,   96,  128,  160,  192,  224,
  256,  288,  320,  352,  384,  416,  448,  480,
  512,  544,  576,  608,  640,  672,  704,  736,
  768,  800,  832,  864,  896,  928,  960,  992,
 1024, 1056, 1088, 1120, 1152, 1184, 1216, 1248,
 1280, 1312, 1344, 1376, 1408, 1440, 1472, 1504,
 1536, 1568, 1600, 1632, 1664, 1696, 1728, 1760,
 1792, 1824, 1856, 1888, 1920, 1952, 1984, 2016,
 2048, 2080, 2112, 2144, 2176, 2208, 2240, 2272,
 2304, 2336, 2368, 2400, 2432, 2464, 2496, 2528,
 2560, 2592, 2624, 2656, 2688, 2720, 2752, 2784,
 2816, 2848, 2880, 2912, 2944, 2976, 3008, 3040,
 3072, 3104, 3136, 3168, 3200, 3232, 3264, 3296,
 3328, 3360, 3392, 3424, 3456, 3488, 3520, 3552,
 3584, 3616, 3648, 3680, 3712, 3744, 3776, 3808,
 3840, 3872, 3904, 3936, 3968, 4000, 4032, 4064,
 4095, 4064, 4032, 4000, 3968, 3936, 3904, 3872,
 3840, 3808, 3776, 3744, 3712, 3680, 3648, 3616,
 3584, 3552, 3520, 3488, 3456, 3424, 3392, 3360,
 3328, 3296, 3264, 3232, 3200, 3168, 3136, 3104,
 3072, 3040, 3008, 2976, 2944, 2912, 2880, 2848,
 2816, 2784, 2752, 2720, 2688, 2656, 2624, 2592,
 2560, 2528, 2496, 2464, 2432, 2400, 2368, 2336,
 2304, 2272, 2240, 2208, 2176, 2144, 2112, 2080,
 2048, 2016, 1984, 1952, 1920, 1888, 1856, 1824,
 1792, 1760, 1728, 1696, 1664, 1632, 1600, 1568,
 1536, 1504, 1472, 1440, 1408, 1376, 1344, 1312,
 1280, 1248, 1216, 1184, 1152, 1120, 1088, 1056,
 1024,  992,  960,  928,  896,  864,  832,  800,
  768,  736,  704,  672,  640,  608,  576,  544,
  512,  480,  448,  416,  384,  352,  320,  288,
  256,  224,  192,  160,  128,   96,   64,   32
};

uint8_t arr3_index=0; //指向arr3的第几个元素 索引

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
HAL_TIM_Base_Start_IT(&htim1);

// for (uint8_t addr = 1; addr < 128; addr++) {
//     if (HAL_I2C_IsDeviceReady(&hi2c2, addr<<1, 1, 100) == HAL_OK) {
//         printf("Found device at 7-bit addr: 0x%02X\r\n", addr);
//     }
// }
// printf("Scan done.\r\n");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
if (ADC_flag==1)
{
//   DAC_writebytes(&(arr1[arr1_index]));
//  printf("send over");
//   if (++arr1_index==2)
//   {
//   arr1_index=0;
//   }
//   ADC_flag=0;


  DAC_writebytes(&(arr2[arr2_index]));
 printf("send over");
  if (++arr2_index==256)
  {
  arr2_index=0;
  }
  ADC_flag=0;
  
}

    /* USER CODE BEGIN 3 */
  }
    /* USER CODE BEGIN 3 */
  
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
