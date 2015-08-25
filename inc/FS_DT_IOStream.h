#ifndef FS_DT_IOSTREAM_H
#define FS_DT_IOSTREAM_H

typedef struct
{
  uint16_t(*writeBytes)(const char * bytes, uint16_t numBytes);
  uint16_t(*writeLine)(const char * line);

  uint16_t(*bytesAvailableToRead)(void);
  char(*peek)(void);
  uint16_t(*readBytes)(char * buf, uint16_t numBytes);
  uint16_t(*readLine)(char * buf);
  uint16_t(*readLineTruncate)(char * buf, uint16_t maxLen);

}FS_DT_IOStream_t;

#endif // FS_DT_IOSTREAM_H
