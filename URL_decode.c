/**
  ******************************************************************************
  * @file     URL_decode.c
  * @author   Vipin , TechDots Firmware Team
  * @version  V1.0.0
  * @date     14-June-2021
  * @brief    This file provides functions to manage the following
  *
  *           - decode the url string.
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
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
char *url_Decode(const char *str);

/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : url_Decode
* Description    : Decode the URL string
* Parameter      : URL String
* Return         : decoded sring
*******************************************************************************/
char *url_Decode(const char *str) {
  int d = 0; /* whether or not the string is decoded */

  char *dStr = malloc(strlen(str) + 1);
  char eStr[] = "00"; /* for a hex code */

  strcpy(dStr, str);

  while(!d) {
    d = 1;
    int i; /* the counter for the string */

    for(i=0;i<strlen(dStr);++i) {

      if(dStr[i] == '%') {
        if(dStr[i+1] == 0)
          return dStr;

        if(isxdigit(dStr[i+1]) && isxdigit(dStr[i+2])) {

          d = 0;

          /* combine the next to numbers into one */
          eStr[0] = dStr[i+1];
          eStr[1] = dStr[i+2];

          /* convert it to decimal */
          long int x = strtol(eStr, NULL, 16);

          /* remove the hex */
          memmove(&dStr[i+1], &dStr[i+3], strlen(&dStr[i+3])+1);

          dStr[i] = x;
        }
      }
    }
  }

  return dStr;
}
/* End of Function url_Decode()**********************************************/

/*******************************************************************************
* Function Name  : main
* Description    : initialization and print application.
* Parameter      : None
* Return         : status
*******************************************************************************/
int main()
{
	char url_string[]= "techdots%40India%40123", *decoded_string;

	decoded_string = url_Decode(url_string);

    printf("\n\rURL String: %s",url_string);
    printf("\n\rDecoded String: %s\n\r",decoded_string);


	return 0;
}
/* End of Function main()**********************************************/

/************** (C) COPYRIGHT 2021 TechDots Pvt Ltd *****END OF FILE****/
