#ifndef FS_DT_USART_H
#define FS_DT_USART_H

typedef struct
{
  uint16_t(*writeBytes)(const char * bytes, uint16_t numBytes);
  uint16_t(*writeLine)(const char * line);

  uint16_t(*readBytes)(const char * buf, uint16_t numBytes);
  uint16_t(*readLine)(const char * buf);

}FS_DT_USARTDriver_t;

#endif // FS_DT_USART_H
