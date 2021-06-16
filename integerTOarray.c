/**
  ******************************************************************************
  * @file     integerTOarray.c
  * @author   Vipin , TechDots Firmware Team
  * @version  V1.0.0
  * @date     16-June-2021
  * @brief    This file provides functions to manage the following
  *
  *           - convert integer to character array.
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
#include <stdlib.h>
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
   typedef enum {false, true} bool;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
   #define SWAP(a, b) (a ^= b ^= a ^=b)

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : reverse_string
* Description    : reverse the string
* Parameter      : str- Pointer to the string, length- String length
* Return         : None
*******************************************************************************/
void reverse_string(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        SWAP(*(str+start), *(str+end));
        start++;
        end--;
    }
}
/* End of Function reverse_string()**********************************************/

/*******************************************************************************
* Function Name  : itoa
* Description    : conversion of integer data to character array
* Parameter      : num- Integer number, str- point of the array, base - (2:binary, 10:decimel, 16:Hex)
* Return         : None
*******************************************************************************/
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse_string(str, i);

    return str;
}

/* End of Function itoa()**********************************************/

/*******************************************************************************
* Function Name  : main
* Description    : initialization and print application.
* Parameter      : None
* Return         : status
*******************************************************************************/
int main()
{
	char str[100];
	itoa(1567, str, 10);
    printf("\n\rBase:10 --> %s",str);

    itoa(-1567, str, 10);
    printf("\n\rBase:10 --> %s",str);

    itoa(1567, str, 2);
    printf("\n\rBase:2 --> %s",str);

    itoa(1567, str, 8);
    printf("\n\rBase:8 --> %s",str);

    itoa(1567, str, 16);
    printf("\n\rBase:16 --> %s",str);

	return 0;
}
/* End of Function main()**********************************************/

/************** (C) COPYRIGHT 2021 TechDots Pvt Ltd *****END OF FILE****/
