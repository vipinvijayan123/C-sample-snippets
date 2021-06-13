/**
  ******************************************************************************
  * @file     Blink_Print.c
  * @author   Vipin , TechDots Firmware Team
  * @version  V1.0.0
  * @date     13-June-2021
  * @brief    This file provides functions to manage the following
  *
  *           - millisecond delay.
  *			  - Print string in sequence format
  *
  *  @verbatim
  *
  *          ===================================================================
  *                             Working of chip/peripheral/Algorithm
  *          ===================================================================
  *
  *          Heading No.1
  *          =============
  *          Explanation
  *
  *          Heading No.2
  *          =============
  *          Explanation
  *          ===================================================================
  *                              How to use this driver / source
  *          ===================================================================
  *            -
  *            -
  *            -
  *            -
  *
  *  @endverbatim
  *
  ******************************************************************************
  *
  * <h2><center>&copy; COPYRIGHT 2021 TechDots Pvt Ltd</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <time.h>
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void sec_delay(int number_of_seconds);
void ms_delay(int number_of_milliseconds);

/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : sec_delay
* Description    : Generate delay in seconds.
* Parameter      : number of seconds :
* Return         : None
*******************************************************************************/
void sec_delay(int number_of_seconds)
{
	// Converting time into Milliseconds
	int milli_seconds = 1000 * number_of_seconds;

	// Get clock ime
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds)
		;
}
/* End of Function sec_delay()**********************************************/

/*******************************************************************************
* Function Name  : ms_delay
* Description    : Generate delay in milliseconds.
* Parameter      : number of seconds :
* Return         : None
*******************************************************************************/
void ms_delay(int number_of_milliseconds)
{

	// Get clock time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + number_of_milliseconds)
		;
}
/* End of Function ms_delay()**********************************************/

/*******************************************************************************
* Function Name  : main
* Description    : initialization and print application.
* Parameter      : None
* Return         : status
*******************************************************************************/
int main()
{
	char string_index=0, prnt_string_len=0, prnt_string[]= "...TechDots Private Limited...";

	prnt_string_len = strlen(prnt_string);

	for (string_index = 0; string_index < prnt_string_len; string_index++) {

		printf("%c", prnt_string[string_index]);
		ms_delay(100);
	}

	return 0;
}
/* End of Function main()**********************************************/

/************** (C) COPYRIGHT 2021 TechDots Pvt Ltd *****END OF FILE****/
