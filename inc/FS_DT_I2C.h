#ifndef FS_DT_I2C_H
#define FS_DT_I2C_H

typedef struct
{
  _Bool(*readBytes)(uint8_t addr, char * buf, uint16_t numBytes, _Bool stop);
  _Bool(*writeBytes)(uint8_t addr, char * buf, uint16_t numBytes, _Bool stop);

}FS_DT_I2CDriver_t;

#endif // FS_DT_I2C_H
