/**
 *******************************************************************************
 *
 * @file
 *
 * @brief	Generic byte stream types.
 *
 *******************************************************************************
 */
 
// Preprocessor guard.
#ifndef FS_DT_IOSTREAM_H
#define FS_DT_IOSTREAM_H

/**
 *******************************************************************************
 *
 * @brief Abstract data type representing a generic byte stream capable of being
 *        written to and read from.
 *
 *******************************************************************************
 */
typedef struct
{
  /**
   *****************************************************************************
   *
   * @brief   Write a specified number of bytes to the stream.
   * 
   * @param   bytes     [in]  The input buffer.
   * @param   numBytes  [in]  The number of bytes to write.
   * 
   * @return  The number of bytes written to the stream.
   *
   *****************************************************************************
   */
  uint16_t(*writeBytes)(const char * bytes, uint16_t numBytes);
  
  /**
   *****************************************************************************
   *
   * @brief   Write a line to the stream. 
   *
   *          Line ending characters (determined by the implementation function) 
   *          will be appended.
   *
   * @param   line       [in]   Pointer to the start of a NULL-terminated string 
   *                            containing the text to be written. Line ending 
   *                            characters will be added and so are not required.
   *
   * @return  The number of bytes written to the stream.
   *
   *****************************************************************************
   */
  uint16_t(*writeLine)(const char * line);

  /**
   *****************************************************************************
   *
   * @brief   Query the number of bytes available to read.
   *
   * @return  The number of bytes available to read.
   *
   *****************************************************************************
   */
  uint16_t(*bytesAvailableToRead)(void);
  
  /**
   *****************************************************************************
   *
   * @brief   Inspect a byte in the stream's buffer without removing it.
   *
   * @param   depth     [in]  Distance from the front of the read queue (i.e.
   *                          the next byte to be read has depth 0, the byte 
   *                          after that has depth 1 and so on).
   *
   * @return  The byte value. In the case of an error (e.g. a byte does not 
   *          exist at that depth) return an implementation-specific error code.
   *
   *
   *****************************************************************************
   */
  char(*peek)(uint16_t depth);
  
  /**
   *****************************************************************************
   *
   * @brief   Read a specified number of bytes from the stream. If insufficient
   *          bytes are available, read all available bytes.
   *
   * @param   buf       [out]       The target buffer.
   * @param   numBytes  [in]        The requested number of bytes.
   *
   * @return  The number of bytes read.
   *
   *****************************************************************************
   */
  uint16_t(*readBytes)(char * buf, uint16_t numBytes);
  
  /**
   *****************************************************************************
   *
   * @brief   Read the next available line from the stream. The implementation
   *          must define the line-ending sequence it uses to determine when
   *          a line is available. Line-ending characters are removed and the
   *          function outputs a NULL-terminated string.
   *
   * @param   buffer    [out]       The target buffer.
   *
   * @return  The length of the output string *not* including the 
   *          NULL-terminator.
   *
   *****************************************************************************
   */
  uint16_t(*readLine)(char * buf);
  
  /**
   *****************************************************************************
   *
   * @brief   Read the next available line from the stream but truncate the
   *          output. 
   *
   *          The implementation must define the line-ending sequence it uses to
   *          determine when a line is available. Line-ending characters are 
   *          removed and the function outputs a NULL-terminated string. Where 
   *          the output string would exceed the maximum specified length,
   *          truncate the string appropriately whilst still ensuring that the
   *          NULL-terminator is the last byte in the output.
   *
   * @param   buffer    [out]       The target buffer.
   * @param   maxLen    [in]        The maximum permissible length of the output
   *                                (including the NULL-terminator) in bytes.
   *
   * @return  The length of the output string *not* including the 
   *          NULL-terminator.
   *
   *****************************************************************************
   */
  uint16_t(*readLineTruncate)(char * buf, uint16_t maxLen);

}FS_DT_IOStream_t;

#endif // FS_DT_IOSTREAM_H
