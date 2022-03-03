/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-03 17:25:20
 * @LastEditTime: 2022-03-03 17:25:20
 * @Description: 
 */

void HW_I2C_Port_Init(void);
uint8_t HW_I2C_Init(M4_I2C_TypeDef* pstcI2Cx,uint32_t baudrate);
uint8_t I2C_Write_data(M4_I2C_TypeDef* pstcI2Cx,uint8_t device_addr,uint8_t addr, const uint8_t *data, uint16_t len);
uint8_t I2C_Read_data(M4_I2C_TypeDef* pstcI2Cx,uint8_t device_addr,uint8_t addr, uint8_t *data, uint16_t len);	
uint8_t I2C_Write_Buffer(M4_I2C_TypeDef* pstcI2Cx,uint8_t device_addr,const uint8_t *data, uint16_t len);	
uint8_t I2C_Read_Buffer(M4_I2C_TypeDef* pstcI2Cx,uint8_t device_addr, uint8_t *data, uint16_t len);	

