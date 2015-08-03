/**
 *******************************************************************************
 *
 * @file  FS_DT_GPIO.h
 *
 * @brief FirmwareSavvy generic GPIO abstraction datatypes header.
 *
 * @author Andy Norris [andy@firmwaresavvy.com]
 *
 *******************************************************************************
 */

// Preprocessor guard.
#ifndef FS_DT_GPIO_H
#define FS_DT_GPIO_H

/*------------------------------------------------------------------------------
------------------------------ START INCLUDES ----------------------------------
------------------------------------------------------------------------------*/

// C standard library includes.
#include <stdint.h>

/*------------------------------------------------------------------------------
------------------------------- END INCLUDES -----------------------------------
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
---------------------------- START PUBLIC TYPES --------------------------------
------------------------------------------------------------------------------*/

typedef struct
{
  uint8_t block;
  uint8_t port;
  uint16_t bit;

}FS_DT_GPIO_Pin_t;

typedef enum
{
  FS_DT_GPIO_Input  = 0,
  FS_DT_GPIO_Output = 1

}FS_DT_GPIO_Direction_t;

typedef enum
{
  FS_DT_GPIO_LineLevel_Low    = 0,
  FS_DT_GPIO_LineLevel_High   = 1,
  FS_DT_GPIO_LineLevel_Error  = 2

}FS_DT_GPIO_LineLevel_t;

typedef enum
{
  FS_DT_GPIO_NoPull     = 0,
  FS_DT_GPIO_PullUp     = 1,
  FS_DT_GPIO_PullDown   = 2,
  FS_DT_GPIO_PullUpDown = 3

}FS_DT_GPIO_PullUpDown_t;

typedef enum
{
  FS_DT_GPIO_OutputType_PP = 0,
  FS_DT_GPIO_OutputType_OD = 1

}FS_DT_GPIO_OutputType_t;

typedef enum
{
  FS_DT_GPIO_RiseTime_Shortest  = 0,
  FS_DT_GPIO_RiseTime_Moderate  = 1,
  FS_DT_GPIO_RiseTime_Longest   = 2

}FS_DT_GPIO_RiseTime_t;

typedef struct
{
  FS_DT_GPIO_Pin_t pin;
  FS_DT_GPIO_Direction_t direction;
  FS_DT_GPIO_LineLevel_t initLineLevel;
  FS_DT_GPIO_PullUpDown_t pull;
  FS_DT_GPIO_OutputType_t outputType;
  FS_DT_GPIO_RiseTime_t riseTime;

}FS_DT_GPIO_PinInitStruct_t;

typedef struct
{
  // Sets an already registered pin up with an entire new init profile.
  _Bool(*reconfig)(FS_DT_GPIO_PinInitStruct_t * initStruct);

  _Bool(*setPinDirection)(int16_t pinIndex, FS_DT_GPIO_Direction_t dir);
  FS_DT_GPIO_Direction_t(*getPinDirection)(int16_t pinIndex);

  _Bool(*setLineLevel)(int16_t pinIndex, FS_DT_GPIO_LineLevel_t level);
  FS_DT_GPIO_LineLevel_t(*getLineLevel)(int16_t pinIndex);

  _Bool(*setPull)(int16_t pinIndex, FS_DT_GPIO_PullUpDown_t pull);
  FS_DT_GPIO_PullUpDown_t(*getPull)(int16_t pinIndex);

  _Bool(*setOutputType)(int16_t pinIndex, FS_DT_GPIO_OutputType_t outputType);
  FS_DT_GPIO_OutputType_t(*getOutputType)(int16_t pinIndex);

  _Bool(*setRiseTime)(int16_t pinIndex, FS_DT_GPIO_RiseTime_t riseTime);
  FS_DT_GPIO_RiseTime_t(*getRiseTime)(int16_t pinIndex);

}FS_DT_GPIO_PinControlInterface_t;

typedef struct
{
  // Registers an external GPIO block - e.g. a port expander.
  int8_t(*registerExternGpioBlock)(FS_DT_GPIO_PinControlInterface_t * controlInterface);

  // Pin first configuration - registers an entry in the pin database.
  int16_t(*registerPin)(FS_DT_GPIO_PinInitStruct_t * initStruct);

  // Encapsulates pin control functions.
  FS_DT_GPIO_PinControlInterface_t ctrl;

}FS_DT_GPIO_ControlInterface_t;

/*------------------------------------------------------------------------------
----------------------------- END PUBLIC TYPES ---------------------------------
------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
---------------------- START PUBLIC FUNCTION PROTOTYPES -----------------------
------------------------------------------------------------------------------*/

void FS_DT_GPIO_PinInitStructInit(FS_DT_GPIO_PinInitStruct_t * initStruct);

/*-----------------------------------------------------------------------------
----------------------- END PUBLIC FUNCTION PROTOTYPES ------------------------
------------------------------------------------------------------------------*/

#endif // FS_DT_GPIO_H
