/**
 *******************************************************************************
 *
 * @file  FS_DT_GPIO.c
 *
 * @brief FirmwareSavvy generic GPIO abstraction datatypes helper functions.
 *
 * @author Andy Norris [andy@firmwaresavvy.com]
 *
 *******************************************************************************
 */

/*------------------------------------------------------------------------------
------------------------------ START INCLUDES ----------------------------------
------------------------------------------------------------------------------*/

// FS_Datatypes configuration header.
#include "FS_DT_Conf.h"

// Own header.
#include "FS_DT_GPIO.h"

/*------------------------------------------------------------------------------
------------------------------- END INCLUDES -----------------------------------
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
-------------------------- START PUBLIC FUNCTIONS ------------------------------
------------------------------------------------------------------------------*/

/**
 *******************************************************************************
 *
 * @brief See API reference in header file.
 *
 *******************************************************************************
 */
void FS_DT_GPIO_PinInitStructInit(FS_DT_GPIO_PinInitStruct_t * initStruct)
{
  // Check the parameters if in debug mode.
  #ifdef FS_DT_DO_ASSERT_PARAMS
  FS_Assert(initStruct != NULL);
  #endif // defined DO_ASSERT_PARAMS

  /*
  Init the pin to be native (block = 0) but set both other fields
  to full-scale to make it obvious the struct has been initialised.
  */
  initStruct->pin.block = 0;
  initStruct->pin.port = 0xFF;
  initStruct->pin.bit = 0xFFFF;

  // Init the rest of the struct to safe default values.
  initStruct->direction = FS_DT_GPIO_Input;
  initStruct->initLineLevel = FS_DT_GPIO_LineLevel_Low;
  initStruct->outputType = FS_DT_GPIO_OutputType_PP;
  initStruct->pull = FS_DT_GPIO_NoPull;
  initStruct->riseTime = FS_DT_GPIO_RiseTime_Longest;
}

/*------------------------------------------------------------------------------
--------------------------- END PUBLIC FUNCTIONS -------------------------------
------------------------------------------------------------------------------*/
