
#ifndef __BNO055_H__
#define __BNO055_H__

#include "asf.h"

typedef int8_t		s8;
typedef int16_t		s16;
typedef int32_t		s32;
typedef int64_t		s64;

typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;

#define BNO055_STARTUP_TIME_MS 700

#define BNO055_CLK_SRC_EXTERNAL	1
#define BNO055_CLK_SRC_INTERNAL	0

/********************************************************/
/**\name	I2C ADDRESS DEFINITION FOR BNO055           */
/********************************************************/
#if (ADDR0_SENS_LEVEL == IOPORT_PIN_LEVEL_LOW)
	#define BNO055_TWI_ADDR_SENSOR		0x28
#else
	#define BNO055_TWI_ADDR_SENSOR		0x29
#endif


/***************************************************/
/**\name	REGISTER ADDRESS DEFINITION  */
/***************************************************/
/* Page id register definition*/
#define BNO055_PAGE_ID_ADDR				    (0X07)

/* PAGE0 REGISTER DEFINITION START*/
typedef enum bno055_register_addr_t
{
	BNO055_CHIP_ID_ADDR					= 0x00,
	BNO055_ACCEL_REV_ID_ADDR			= (0x01),
	BNO055_MAG_REV_ID_ADDR              = (0x02),
	BNO055_GYRO_REV_ID_ADDR             = (0x03),
	BNO055_SW_REV_ID_LSB_ADDR			= (0x04),
	BNO055_SW_REV_ID_MSB_ADDR			= (0x05),
	BNO055_BL_REV_ID_ADDR				= (0X06),
	/* Accel data register*/
	BNO055_ACCEL_DATA_X_LSB_ADDR		= (0X08),
	BNO055_ACCEL_DATA_X_MSB_ADDR		= (0X09),
	BNO055_ACCEL_DATA_Y_LSB_ADDR		= (0X0A),
	BNO055_ACCEL_DATA_Y_MSB_ADDR		= (0X0B),
	BNO055_ACCEL_DATA_Z_LSB_ADDR		= (0X0C),
	BNO055_ACCEL_DATA_Z_MSB_ADDR		= (0X0D),

	/*Mag data register*/
	BNO055_MAG_DATA_X_LSB_ADDR			= (0X0E),
	BNO055_MAG_DATA_X_MSB_ADDR			= (0X0F),
	BNO055_MAG_DATA_Y_LSB_ADDR			= (0X10),
	BNO055_MAG_DATA_Y_MSB_ADDR			= (0X11),
	BNO055_MAG_DATA_Z_LSB_ADDR			= (0X12),
	BNO055_MAG_DATA_Z_MSB_ADDR			= (0X13),

	/*Gyro data registers*/
	BNO055_GYRO_DATA_X_LSB_ADDR			= (0X14),
	BNO055_GYRO_DATA_X_MSB_ADDR			= (0X15),
	BNO055_GYRO_DATA_Y_LSB_ADDR			= (0X16),
	BNO055_GYRO_DATA_Y_MSB_ADDR			= (0X17),
	BNO055_GYRO_DATA_Z_LSB_ADDR			= (0X18),
	BNO055_GYRO_DATA_Z_MSB_ADDR			= (0X19),

	/*Euler data registers*/
	BNO055_EULER_H_LSB_ADDR				= (0X1A),
	BNO055_EULER_H_MSB_ADDR				= (0X1B),

	BNO055_EULER_R_LSB_ADDR				= (0X1C),
	BNO055_EULER_R_MSB_ADDR				= (0X1D),

	BNO055_EULER_P_LSB_ADDR				= (0X1E),
	BNO055_EULER_P_MSB_ADDR				= (0X1F),

	/*Quaternion data registers*/
	BNO055_QUATERNION_DATA_W_LSB_ADDR	= (0X20),
	BNO055_QUATERNION_DATA_W_MSB_ADDR	= (0X21),
	BNO055_QUATERNION_DATA_X_LSB_ADDR	= (0X22),
	BNO055_QUATERNION_DATA_X_MSB_ADDR	= (0X23),
	BNO055_QUATERNION_DATA_Y_LSB_ADDR	= (0X24),
	BNO055_QUATERNION_DATA_Y_MSB_ADDR	= (0X25),
	BNO055_QUATERNION_DATA_Z_LSB_ADDR	= (0X26),
	BNO055_QUATERNION_DATA_Z_MSB_ADDR	= (0X27),

	/* Linear acceleration data registers*/
	BNO055_LINEAR_ACCEL_DATA_X_LSB_ADDR	= (0X28),
	BNO055_LINEAR_ACCEL_DATA_X_MSB_ADDR	= (0X29),
	BNO055_LINEAR_ACCEL_DATA_Y_LSB_ADDR	= (0X2A),
	BNO055_LINEAR_ACCEL_DATA_Y_MSB_ADDR	= (0X2B),
	BNO055_LINEAR_ACCEL_DATA_Z_LSB_ADDR	= (0X2C),
	BNO055_LINEAR_ACCEL_DATA_Z_MSB_ADDR	= (0X2D),

	/*Gravity data registers*/
	BNO055_GRAVITY_DATA_X_LSB_ADDR		= (0X2E),
	BNO055_GRAVITY_DATA_X_MSB_ADDR		= (0X2F),
	BNO055_GRAVITY_DATA_Y_LSB_ADDR		= (0X30),
	BNO055_GRAVITY_DATA_Y_MSB_ADDR		= (0X31),
	BNO055_GRAVITY_DATA_Z_LSB_ADDR		= (0X32),
	BNO055_GRAVITY_DATA_Z_MSB_ADDR		= (0X33),

	/* Temperature data register*/
	BNO055_TEMP_ADDR					= (0X34),

	/* Status registers*/
	BNO055_CALIB_STAT_ADDR				= (0X35),
	BNO055_SELFTEST_RESULT_ADDR			= (0X36),
	BNO055_INTR_STAT_ADDR				= (0X37),
	BNO055_SYS_CLK_STAT_ADDR			= (0X38),
	BNO055_SYS_STAT_ADDR				= (0X39),
	BNO055_SYS_ERR_ADDR					= (0X3A),

	/* Unit selection register*/
	BNO055_UNIT_SEL_ADDR				= (0X3B),
	BNO055_DATA_SELECT_ADDR				= (0X3C),

	/* Mode registers*/
	BNO055_OPR_MODE_ADDR				= (0X3D),
	BNO055_PWR_MODE_ADDR				= (0X3E),

	BNO055_SYS_TRIGGER_ADDR				= (0X3F),
	BNO055_TEMP_SOURCE_ADDR				= (0X40),
	/* Axis remap registers*/
	BNO055_AXIS_MAP_CONFIG_ADDR			= (0X41),
	BNO055_AXIS_MAP_SIGN_ADDR			= (0X42),

	/* SIC registers*/
	BNO055_SIC_MATRIX_0_LSB_ADDR		= (0X43),
	BNO055_SIC_MATRIX_0_MSB_ADDR		= (0X44),
	BNO055_SIC_MATRIX_1_LSB_ADDR		= (0X45),
	BNO055_SIC_MATRIX_1_MSB_ADDR		= (0X46),
	BNO055_SIC_MATRIX_2_LSB_ADDR		= (0X47),
	BNO055_SIC_MATRIX_2_MSB_ADDR		= (0X48),
	BNO055_SIC_MATRIX_3_LSB_ADDR		= (0X49),
	BNO055_SIC_MATRIX_3_MSB_ADDR		= (0X4A),
	BNO055_SIC_MATRIX_4_LSB_ADDR		= (0X4B),
	BNO055_SIC_MATRIX_4_MSB_ADDR		= (0X4C),
	BNO055_SIC_MATRIX_5_LSB_ADDR		= (0X4D),
	BNO055_SIC_MATRIX_5_MSB_ADDR		= (0X4E),
	BNO055_SIC_MATRIX_6_LSB_ADDR		= (0X4F),
	BNO055_SIC_MATRIX_6_MSB_ADDR		= (0X50),
	BNO055_SIC_MATRIX_7_LSB_ADDR		= (0X51),
	BNO055_SIC_MATRIX_7_MSB_ADDR		= (0X52),
	BNO055_SIC_MATRIX_8_LSB_ADDR		= (0X53),
	BNO055_SIC_MATRIX_8_MSB_ADDR		= (0X54),

	/* Accelerometer Offset registers*/
	BNO055_ACCEL_OFFSET_X_LSB_ADDR		= (0X55),
	BNO055_ACCEL_OFFSET_X_MSB_ADDR		= (0X56),
	BNO055_ACCEL_OFFSET_Y_LSB_ADDR		= (0X57),
	BNO055_ACCEL_OFFSET_Y_MSB_ADDR		= (0X58),
	BNO055_ACCEL_OFFSET_Z_LSB_ADDR		= (0X59),
	BNO055_ACCEL_OFFSET_Z_MSB_ADDR		= (0X5A),

	/* Magnetometer Offset registers*/
	BNO055_MAG_OFFSET_X_LSB_ADDR		= (0X5B),
	BNO055_MAG_OFFSET_X_MSB_ADDR		= (0X5C),
	BNO055_MAG_OFFSET_Y_LSB_ADDR		= (0X5D),
	BNO055_MAG_OFFSET_Y_MSB_ADDR		= (0X5E),
	BNO055_MAG_OFFSET_Z_LSB_ADDR		= (0X5F),
	BNO055_MAG_OFFSET_Z_MSB_ADDR		= (0X60),

	/* Gyroscope Offset registers*/
	BNO055_GYRO_OFFSET_X_LSB_ADDR		= (0X61),
	BNO055_GYRO_OFFSET_X_MSB_ADDR		= (0X62),
	BNO055_GYRO_OFFSET_Y_LSB_ADDR		= (0X63),
	BNO055_GYRO_OFFSET_Y_MSB_ADDR		= (0X64),
	BNO055_GYRO_OFFSET_Z_LSB_ADDR		= (0X65),
	BNO055_GYRO_OFFSET_Z_MSB_ADDR		= (0X66),

	/* Radius registers*/
	BNO055_ACCEL_RADIUS_LSB_ADDR		= (0X67),
	BNO055_ACCEL_RADIUS_MSB_ADDR		= (0X68),
	BNO055_MAG_RADIUS_LSB_ADDR			= (0X69),
	BNO055_MAG_RADIUS_MSB_ADDR			= (0X6A),
	/* PAGE0 REGISTERS DEFINITION END*/

	/* PAGE1 REGISTERS DEFINITION START*/
	/* Configuration registers*/
	BNO055_ACCEL_CONFIG_ADDR				= (0X08),
	BNO055_MAG_CONFIG_ADDR					= (0X09),
	BNO055_GYRO_CONFIG_ADDR					= (0X0A),
	BNO055_GYRO_MODE_CONFIG_ADDR			= (0X0B),
	BNO055_ACCEL_SLEEP_CONFIG_ADDR			= (0X0C),
	BNO055_GYRO_SLEEP_CONFIG_ADDR			= (0X0D),
	BNO055_MAG_SLEEP_CONFIG_ADDR			= (0x0E),

	/* Interrupt registers*/
	BNO055_INT_MASK_ADDR					= (0X0F),
	BNO055_INT_ADDR							= (0X10),
	BNO055_ACCEL_ANY_MOTION_THRES_ADDR		= (0X11),
	BNO055_ACCEL_INTR_SETTINGS_ADDR			= (0X12),
	BNO055_ACCEL_HIGH_G_DURN_ADDR			= (0X13),
	BNO055_ACCEL_HIGH_G_THRES_ADDR			= (0X14),
	BNO055_ACCEL_NO_MOTION_THRES_ADDR		= (0X15),
	BNO055_ACCEL_NO_MOTION_SET_ADDR			= (0X16),
	BNO055_GYRO_INTR_SETING_ADDR			= (0X17),
	BNO055_GYRO_HIGHRATE_X_SET_ADDR			= (0X18),
	BNO055_GYRO_DURN_X_ADDR					= (0X19),
	BNO055_GYRO_HIGHRATE_Y_SET_ADDR			= (0X1A),
	BNO055_GYRO_DURN_Y_ADDR					= (0X1B),
	BNO055_GYRO_HIGHRATE_Z_SET_ADDR			= (0X1C),
	BNO055_GYRO_DURN_Z_ADDR					= (0X1D),
	BNO055_GYRO_ANY_MOTION_THRES_ADDR		= (0X1E),
	BNO055_GYRO_ANY_MOTION_SET_ADDR			= (0X1F)
	/* PAGE1 REGISTERS DEFINITION END*/
}bno055_register_addr_t;




#define BNO055_MDELAY_DATA_TYPE		u32

/*< This refers BNO055 return type as s8 */
#define BNO055_RETURN_FUNCTION_TYPE	s8

/* Compile switch definition for Float and double*/
/**************************************************************/
/**\name	STRUCTURE DEFINITIONS                         */
/**************************************************************/
///*!
//*	@brief bno055 struct
//*/
//struct bno055_t {
//u8 chip_id;/**< chip_id of bno055 */
//u16 sw_rev_id;/**< software revision id of bno055 */
//u8 page_id;/**< page_id of bno055 */
//u8 accel_rev_id;/**< accel revision id of bno055 */
//u8 mag_rev_id;/**< mag revision id of bno055 */
//u8 gyro_rev_id;/**< gyro revision id of bno055 */
//u8 bl_rev_id;/**< boot loader revision id of bno055 */
//u8 dev_addr;/**< i2c device address of bno055 */
//BNO055_WR_FUNC_PTR;/**< bus write function pointer */
//BNO055_RD_FUNC_PTR;/**<bus read function pointer */
//void (*delay_msec)(BNO055_MDELAY_DATA_TYPE);/**< delay function pointer */
//};
/*!
* @brief struct for accel data read from registers
*/
struct bno055_accel_t {
s16 x;/**< accel x data */
s16 y;/**< accel y data */
s16 z;/**< accel z data */
};
/*!
* @brief struct for Mag data read from registers
*/
struct bno055_mag_t {
s16 x;/**< mag x data */
s16 y;/**< mag y data */
s16 z;/**< mag z data */
};
/*!
* @brief struct for Gyro data read from registers
*/
struct bno055_gyro_t {
s16 x;/**< gyro x data */
s16 y;/**< gyro y data */
s16 z;/**< gyro z data */
};
/*!
* @brief struct for Euler data read from registers
*/
struct bno055_euler_t {
s16 h;/**< Euler h data */
s16 r;/**< Euler r data */
s16 p;/**< Euler p data */
};
/*!
* @brief struct for Quaternion data read from registers
*/
struct bno055_quaternion_t {
s16 w;/**< Quaternion w data */
s16 x;/**< Quaternion x data */
s16 y;/**< Quaternion y data */
s16 z;/**< Quaternion z data */
};
/*!
* @brief struct for Linear Accel data read from registers
*/
struct bno055_linear_accel_t {
s16 x; /**< Linear Accel x data */
s16 y; /**< Linear Accel y data */
s16 z; /**< Linear Accel z data */
};
/*!
* @brief struct for Gravity data read from registers
*/
struct bno055_gravity_t {
s16 x;/**< Gravity x data */
s16 y;/**< Gravity y data */
s16 z;/**< Gravity z data */
};
/*!
* @brief struct for Accel offset
*/
struct bno055_accel_offset_t{
s16 x;/**< Accel offset x data */
s16 y;/**< Accel offset y data */
s16 z;/**< Accel offset z data */
s16 r;/**< Accel radius r data */
};
/*!
* @brief struct for Gyro offset
*/
struct bno055_gyro_offset_t{
s16 x;/**< Gyro offset x data */
s16 y;/**< Gyro offset y data */
s16 z;/**< Gyro offset z data */
};
/*!
* @brief struct for Mag offset
*/
struct bno055_mag_offset_t{
s16 x;/**< Mag offset x data */
s16 y;/**< Mag offset y data */
s16 z;/**< Mag offset z data */
s16 r;/**< Mag radius r data */
};
/*!
* @brief struct for soft iron calibration matrix
*/
struct bno055_sic_matrix_t {
s16 sic_0;/**< soft iron calibration matrix 0 data */
s16 sic_1;/**< soft iron calibration matrix 1 data */
s16 sic_2;/**< soft iron calibration matrix 2 data */
s16 sic_3;/**< soft iron calibration matrix 3 data */
s16 sic_4;/**< soft iron calibration matrix 4 data */
s16 sic_5;/**< soft iron calibration matrix 5 data */
s16 sic_6;/**< soft iron calibration matrix 6 data */
s16 sic_7;/**< soft iron calibration matrix 7 data */
s16 sic_8;/**< soft iron calibration matrix 8 data */
};
/***************************************************/
/**\name	CONSTANT DEFINITIONS                   */
/***************************************************/
#define  BNO055_INIT_VALUE						((u8)0)
#define  BNO055_GEN_READ_WRITE_LENGTH			((u8)1)
#define  BNO055_LSB_MSB_READ_LENGTH				((u8)2)
#define  BNO055_MAG_POWER_MODE_RANGE			((u8)4)
#define  BNO055_MAG_OPR_MODE_RANGE				((u8)5)
#define  BNO055_ACCEL_POWER_MODE_RANGE          ((u8)6)
#define  BNO055_ACCEL_SLEEP_DURATION_RANGE      ((u8)16)
#define	 BNO055_GYRO_AUTO_SLEEP_DURATION_RANGE	((u8)8)
#define  BNO055_ACCEL_GYRO_BW_RANGE		((u8)8)
#define  BNO055_MAG_OUTPUT_RANGE		((u8)8)
#define  BNO055_ACCEL_RANGE				((u8)5)
#define  BNO055_SHIFT_EIGHT_BITS        ((u8)8)
#define	 BNO055_GYRO_RANGE				((u8)5)
#define  BNO055_ACCEL_SLEEP_MODE_RANGE  ((u8)2)
/*  BNO055 API BNO055_ERROR codes */
#define BNO055_E_NULL_PTR   ((s8)-127)
#define BNO055_OUT_OF_RANGE	((s8)-2)
#define	BNO055_SUCCESS		((u8)0)
#define	BNO055_ERROR		((s8)-1)

/* Selection for bit enable and disable */
#define BNO055_BIT_ENABLE		(0x01)
#define BNO055_BIT_DISABLE		(0x00)

/* Page ID */
#define BNO055_PAGE_ZERO		(0X00)
#define BNO055_PAGE_ONE			(0X01)

/* Enable the temperature source */
#define	BNO055_ACCEL_TEMP_EN	(0x00)
#define	BNO055_GYRO_TEMP_EN		(0x01)
#define	BNO055_MCU_TEMP_EN		(0x03)

/*Accel unit*/
#define BNO055_ACCEL_UNIT_MSQ	(0x00)
#define BNO055_ACCEL_UNIT_MG	(0x01)

/*Gyro unit*/
#define BNO055_GYRO_UNIT_DPS	(0x00)
#define BNO055_GYRO_UNIT_RPS	(0x01)

/* Euler unit*/
#define BNO055_EULER_UNIT_DEG	(0x00)
#define BNO055_EULER_UNIT_RAD	(0x01)

/*Temperature unit*/
#define BNO055_TEMP_UNIT_CELSIUS		(0x00)
#define BNO055_TEMP_UNIT_FAHRENHEIT		(0x01)

/*Accel division factor*/
#define	BNO055_ACCEL_DIV_MSQ	(100.0)
#define	BNO055_ACCEL_DIV_MG		(1)

/*Mag division factor*/
#define BNO055_MAG_DIV_UT	(16.0)

/*Gyro division factor*/
#define BNO055_GYRO_DIV_DPS		(16.0)
#define BNO055_GYRO_DIV_RPS		(900.0)

/*Euler division factor*/
#define BNO055_EULER_DIV_DEG		(16.0)
#define BNO055_EULER_DIV_RAD		(900.0)

/*Linear accel division factor*/
#define	BNO055_LINEAR_ACCEL_DIV_MSQ	(100.0)

/*Gravity accel division factor*/
#define	BNO055_GRAVITY_DIV_MSQ	(100.0)

/* Temperature division factor*/
#define BNO055_TEMP_DIV_FAHRENHEIT	(0.5)
#define BNO055_TEMP_DIV_CELSIUS		(1)

#define	BNO055_MODE_SWITCHING_DELAY        (600)
#define	BNO055_CONFIG_MODE_SWITCHING_DELAY ((u8)20)

/* PAGE-1 definitions*/
/* Accel Range */

#define BNO055_ACCEL_RANGE_2G		(0X00)
#define BNO055_ACCEL_RANGE_4G		(0X01)
#define BNO055_ACCEL_RANGE_8G		(0X02)
#define BNO055_ACCEL_RANGE_16G		(0X03)

/* Accel Bandwidth*/
#define BNO055_ACCEL_BW_7_81HZ		(0x00)
#define BNO055_ACCEL_BW_15_63HZ		(0x01)
#define BNO055_ACCEL_BW_31_25HZ		(0x02)
#define BNO055_ACCEL_BW_62_5HZ		(0X03)
#define BNO055_ACCEL_BW_125HZ		(0X04)
#define BNO055_ACCEL_BW_250HZ		(0X05)
#define BNO055_ACCEL_BW_500HZ		(0X06)
#define BNO055_ACCEL_BW_1000HZ		(0X07)

/* Accel Power mode*/
#define BNO055_ACCEL_NORMAL			(0X00)
#define BNO055_ACCEL_SUSPEND		(0X01)
#define BNO055_ACCEL_LOWPOWER_1		(0X02)
#define BNO055_ACCEL_STANDBY		(0X03)
#define BNO055_ACCEL_LOWPOWER_2		(0X04)
#define BNO055_ACCEL_DEEPSUSPEND	(0X05)

/* Mag data output rate*/
#define BNO055_MAG_DATA_OUTRATE_2HZ			(0X00)
#define BNO055_MAG_DATA_OUTRATE_6HZ			(0X01)
#define BNO055_MAG_DATA_OUTRATE_8HZ			(0X02)
#define BNO055_MAG_DATA_OUTRATE_10HZ		(0X03)
#define BNO055_MAG_DATA_OUTRATE_15HZ		(0X04)
#define BNO055_MAG_DATA_OUTRATE_20HZ		(0X05)
#define BNO055_MAG_DATA_OUTRATE_25HZ		(0X06)
#define BNO055_MAG_DATA_OUTRATE_30HZ		(0X07)

/* Mag Operation mode*/
#define BNO055_MAG_OPERATION_MODE_LOWPOWER				(0X00)
#define BNO055_MAG_OPERATION_MODE_REGULAR				(0X01)
#define BNO055_MAG_OPERATION_MODE_ENHANCED_REGULAR		(0X02)
#define BNO055_MAG_OPERATION_MODE_HIGH_ACCURACY			(0X03)

/* Mag power mode*/
#define BNO055_MAG_POWER_MODE_NORMAL			(0X00)
#define BNO055_MAG_POWER_MODE_SLEEP				(0X01)
#define BNO055_MAG_POWER_MODE_SUSPEND			(0X02)
#define BNO055_MAG_POWER_MODE_FORCE_MODE		(0X03)

/* Gyro range*/
#define BNO055_GYRO_RANGE_2000DPS		(0x00)
#define BNO055_GYRO_RANGE_1000DPS		(0x01)
#define BNO055_GYRO_RANGE_500DPS		(0x02)
#define BNO055_GYRO_RANGE_250DPS		(0x03)
#define BNO055_GYRO_RANGE_125DPS		(0x04)

/* Gyro Bandwidth*/
#define BNO055_GYRO_BW_523HZ	(0x00)
#define BNO055_GYRO_BW_230HZ	(0x01)
#define BNO055_GYRO_BW_116HZ	(0x02)
#define BNO055_GYRO_BW_47HZ		(0x03)
#define BNO055_GYRO_BW_23HZ		(0x04)
#define BNO055_GYRO_BW_12HZ		(0x05)
#define BNO055_GYRO_BW_64HZ		(0x06)
#define BNO055_GYRO_BW_32HZ		(0x07)

/* Gyro power mode*/
#define BNO055_GYRO_POWER_MODE_NORMAL				(0X00)
#define BNO055_GYRO_POWER_MODE_FASTPOWERUP			(0X01)
#define BNO055_GYRO_POWER_MODE_DEEPSUSPEND			(0X02)
#define BNO055_GYRO_POWER_MODE_SUSPEND				(0X03)
#define BNO055_GYRO_POWER_MODE_ADVANCE_POWERSAVE	(0X04)

/* Accel Sleep Duration */
#define BNO055_ACCEL_SLEEP_DURN_0_5MS        (0x05)
/* sets sleep duration to 0.5 ms  */
#define BNO055_ACCEL_SLEEP_DURN_1MS          (0x06)
/* sets sleep duration to 1 ms */
#define BNO055_ACCEL_SLEEP_DURN_2MS          (0x07)
/* sets sleep duration to 2 ms */
#define BNO055_ACCEL_SLEEP_DURN_4MS          (0x08)
/* sets sleep duration to 4 ms */
#define BNO055_ACCEL_SLEEP_DURN_6MS          (0x09)
/* sets sleep duration to 6 ms*/
#define BNO055_ACCEL_SLEEP_DURN_10MS         (0x0A)
/* sets sleep duration to 10 ms */
#define BNO055_ACCEL_SLEEP_DURN_25MS         (0x0B)
 /* sets sleep duration to 25 ms */
#define BNO055_ACCEL_SLEEP_DURN_50MS         (0x0C)
 /* sets sleep duration to 50 ms */
#define BNO055_ACCEL_SLEEP_DURN_100MS        (0x0D)
 /* sets sleep duration to 100 ms */
#define BNO055_ACCEL_SLEEP_DURN_500MS        (0x0E)
 /* sets sleep duration to 500 ms */
#define BNO055_ACCEL_SLEEP_DURN_1S           (0x0F)
/* sets sleep duration to 1 s */

/* Gyro Auto sleep duration*/
#define BNO055_GYRO_No_AUTOSLPDUR		(0x00)
#define	BNO055_GYRO_4MS_AUTOSLPDUR		(0x01)
#define	BNO055_GYRO_5MS_AUTOSLPDUR		(0x02)
#define	BNO055_GYRO_8MS_AUTOSLPDUR		(0x03)
#define	BNO055_GYRO_10MS_AUTOSLPDUR		(0x04)
#define	BNO055_GYRO_15MS_AUTOSLPDUR		(0x05)
#define	BNO055_GYRO_20MS_AUTOSLPDUR		(0x06)
#define	BNO055_GYRO_40MS_AUTOSLPDUR		(0x07)

/* Accel Any/No motion axis selection*/
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_X_AXIS		(0)
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_Y_AXIS		(1)
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_Z_AXIS		(2)

/* Accel High g axis selection*/
#define BNO055_ACCEL_HIGH_G_X_AXIS		(0)
#define BNO055_ACCEL_HIGH_G_Y_AXIS		(1)
#define BNO055_ACCEL_HIGH_G_Z_AXIS		(2)

/* Gyro Any motion axis selection*/
#define BNO055_GYRO_ANY_MOTION_X_AXIS		(0)
#define BNO055_GYRO_ANY_MOTION_Y_AXIS		(1)
#define BNO055_GYRO_ANY_MOTION_Z_AXIS		(2)


/* Gyro High rate axis selection*/
#define BNO055_GYRO_HIGHRATE_X_AXIS		(0)
#define BNO055_GYRO_HIGHRATE_Y_AXIS		(1)
#define BNO055_GYRO_HIGHRATE_Z_AXIS		(2)

/* Axis remap values*/
#define BNO055_REMAP_X_Y			(0X21)
#define BNO055_REMAP_Y_Z			(0X18)
#define BNO055_REMAP_Z_X			(0X06)
#define BNO055_REMAP_X_Y_Z_TYPE0	(0X12)
#define BNO055_REMAP_X_Y_Z_TYPE1	(0X09)
#define BNO055_DEFAULT_AXIS			(0X24)

/* Axis remap sign */
#define	BNO055_REMAP_AXIS_POSITIVE	(0X00)
#define	BNO055_REMAP_AXIS_NEGATIVE	(0X01)

/* Gyro anymotion and high rate filter configuration */
#define	BNO055_GYRO_FILTERED_CONFIG		(0x00)
#define	BNO055_GYRO_UNFILTERED_CONFIG	(0x01)

/* mask definitions*/
#define BNO055_SIC_HEX_0_0_F_F_DATA		(0x00FF)
/****************************************************/
/**\name	ARRAY SIZE DEFINITIONS      */
/***************************************************/
#define BNO055_REV_ID_SIZE						(2)
#define BNO055_ACCEL_DATA_SIZE					(2)
#define BNO055_ACCEL_XYZ_DATA_SIZE				(6)
#define BNO055_MAG_DATA_SIZE					(2)
#define BNO055_MAG_XYZ_DATA_SIZE				(6)
#define BNO055_GYRO_DATA_SIZE					(2)
#define BNO055_GYRO_XYZ_DATA_SIZE				(6)
#define BNO055_EULER_DATA_SIZE					(2)
#define BNO055_EULER_HRP_DATA_SIZE				(6)
#define BNO055_QUATERNION_DATA_SIZE				(2)
#define BNO055_QUATERNION_WXYZ_DATA_SIZE		(8)
#define BNO055_GRAVITY_DATA_SIZE				(2)
#define BNO055_GRAVITY_XYZ_DATA_SIZE			(6)
#define BNO055_ACCEL_OFFSET_ARRAY				(6)
#define BNO055_MAG_OFFSET_ARRAY					(6)
#define BNO055_GYRO_OFFSET_ARRAY				(6)
#define BNO055_SOFT_IRON_CALIBRATION_MATRIX_SIZE		(18)


/*ARRAY INDEX DEFINITIONS*/
#define BNO055_SW_ID_LSB						(0)
#define BNO055_SW_ID_MSB						(1)
#define BNO055_SENSOR_DATA_LSB					(0)
#define BNO055_SENSOR_DATA_MSB					(1)
#define BNO055_SENSOR_DATA_EULER_LSB			(0)
#define BNO055_SENSOR_DATA_EULER_MSB			(1)
#define BNO055_SENSOR_DATA_QUATERNION_LSB		(0)
#define BNO055_SENSOR_DATA_QUATERNION_MSB		(1)

#define BNO055_SENSOR_DATA_QUATERNION_WXYZ_W_LSB			(0)
#define BNO055_SENSOR_DATA_QUATERNION_WXYZ_W_MSB			(1)
#define BNO055_SENSOR_DATA_QUATERNION_WXYZ_X_LSB			(2)
#define BNO055_SENSOR_DATA_QUATERNION_WXYZ_X_MSB			(3)
#define BNO055_SENSOR_DATA_QUATERNION_WXYZ_Y_LSB			(4)
#define BNO055_SENSOR_DATA_QUATERNION_WXYZ_Y_MSB			(5)
#define BNO055_SENSOR_DATA_QUATERNION_WXYZ_Z_LSB			(6)
#define BNO055_SENSOR_DATA_QUATERNION_WXYZ_Z_MSB			(7)

#define BNO055_SENSOR_DATA_XYZ_X_LSB				(0)
#define BNO055_SENSOR_DATA_XYZ_X_MSB				(1)
#define BNO055_SENSOR_DATA_XYZ_Y_LSB				(2)
#define BNO055_SENSOR_DATA_XYZ_Y_MSB				(3)
#define BNO055_SENSOR_DATA_XYZ_Z_LSB				(4)
#define BNO055_SENSOR_DATA_XYZ_Z_MSB				(5)


#define BNO055_SENSOR_DATA_EULER_HRP_H_LSB			(0)
#define BNO055_SENSOR_DATA_EULER_HRP_H_MSB			(1)
#define BNO055_SENSOR_DATA_EULER_HRP_R_LSB			(2)
#define BNO055_SENSOR_DATA_EULER_HRP_R_MSB			(3)
#define BNO055_SENSOR_DATA_EULER_HRP_P_LSB			(4)
#define BNO055_SENSOR_DATA_EULER_HRP_P_MSB			(5)

#define BNO055_SOFT_IRON_CALIB_0_LSB	(0)
#define BNO055_SOFT_IRON_CALIB_0_MSB	(1)
#define BNO055_SOFT_IRON_CALIB_1_LSB	(2)
#define BNO055_SOFT_IRON_CALIB_1_MSB	(3)
#define BNO055_SOFT_IRON_CALIB_2_LSB	(4)
#define BNO055_SOFT_IRON_CALIB_2_MSB	(5)
#define BNO055_SOFT_IRON_CALIB_3_LSB	(6)
#define BNO055_SOFT_IRON_CALIB_3_MSB	(7)
#define BNO055_SOFT_IRON_CALIB_4_LSB	(8)
#define BNO055_SOFT_IRON_CALIB_4_MSB	(9)
#define BNO055_SOFT_IRON_CALIB_5_LSB	(10)
#define BNO055_SOFT_IRON_CALIB_5_MSB	(11)
#define BNO055_SOFT_IRON_CALIB_6_LSB	(12)
#define BNO055_SOFT_IRON_CALIB_6_MSB	(13)
#define BNO055_SOFT_IRON_CALIB_7_LSB	(14)
#define BNO055_SOFT_IRON_CALIB_7_MSB	(15)
#define BNO055_SOFT_IRON_CALIB_8_LSB	(16)
#define BNO055_SOFT_IRON_CALIB_8_MSB	(17)

#define BNO055_SENSOR_OFFSET_DATA_X_LSB	(0)
#define BNO055_SENSOR_OFFSET_DATA_X_MSB	(1)
#define BNO055_SENSOR_OFFSET_DATA_Y_LSB	(2)
#define BNO055_SENSOR_OFFSET_DATA_Y_MSB	(3)
#define BNO055_SENSOR_OFFSET_DATA_Z_LSB	(4)
#define BNO055_SENSOR_OFFSET_DATA_Z_MSB	(5)

#define BNO055_OFFSET_RADIUS_LSB (0)
#define BNO055_OFFSET_RADIUS_MSB (1)
/*********************************************************/
/**\name PAGE0 DATA REGISTERS DEFINITION */
/*********************************************************/
/* Chip ID */
#define BNO055_CHIP_ID_POS             (0)
#define BNO055_CHIP_ID_MSK             (0xFF)
#define BNO055_CHIP_ID_LEN             (8)
#define BNO055_CHIP_ID_REG             BNO055_CHIP_ID_ADDR

/* Accel revision id*/
#define BNO055_ACCEL_REV_ID_POS             (0)
#define BNO055_ACCEL_REV_ID_MSK             (0xFF)
#define BNO055_ACCEL_REV_ID_LEN             (8)
#define BNO055_ACCEL_REV_ID_REG             BNO055_ACCEL_REV_ID_ADDR

/* Mag revision id*/
#define BNO055_MAG_REV_ID_POS             (0)
#define BNO055_MAG_REV_ID_MSK             (0xFF)
#define BNO055_MAG_REV_ID_LEN             (8)
#define BNO055_MAG_REV_ID_REG             BNO055_MAG_REV_ID_ADDR

/* Gyro revision id*/
#define BNO055_GYRO_REV_ID_POS             (0)
#define BNO055_GYRO_REV_ID_MSK             (0xFF)
#define BNO055_GYRO_REV_ID_LEN             (8)
#define BNO055_GYRO_REV_ID_REG             BNO055_GYRO_REV_ID_ADDR

/*Software revision id LSB*/
#define BNO055_SW_REV_ID_LSB_POS             (0)
#define BNO055_SW_REV_ID_LSB_MSK             (0xFF)
#define BNO055_SW_REV_ID_LSB_LEN             (8)
#define BNO055_SW_REV_ID_LSB_REG             BNO055_SW_REV_ID_LSB_ADDR

/*Software revision id MSB*/
#define BNO055_SW_REV_ID_MSB_POS             (0)
#define BNO055_SW_REV_ID_MSB_MSK             (0xFF)
#define BNO055_SW_REV_ID_MSB_LEN             (8)
#define BNO055_SW_REV_ID_MSB_REG             BNO055_SW_REV_ID_MSB_ADDR

/* BOOTLODER revision id*/
#define BNO055_BL_REV_ID_POS             (0)
#define BNO055_BL_REV_ID_MSK             (0xFF)
#define BNO055_BL_REV_ID_LEN             (8)
#define BNO055_BL_REV_ID_REG             BNO055_BL_REV_ID_ADDR

/*Page id*/
#define BNO055_PAGE_ID_POS             (0)
#define BNO055_PAGE_ID_MSK             (0xFF)
#define BNO055_PAGE_ID_LEN             (8)
#define BNO055_PAGE_ID_REG             BNO055_PAGE_ID_ADDR

/* Accel data X-LSB register*/
#define BNO055_ACCEL_DATA_X_LSB_VALUEX_POS             (0)
#define BNO055_ACCEL_DATA_X_LSB_VALUEX_MSK             (0xFF)
#define BNO055_ACCEL_DATA_X_LSB_VALUEX_LEN             (8)
#define BNO055_ACCEL_DATA_X_LSB_VALUEX_REG             \
BNO055_ACCEL_DATA_X_LSB_ADDR

/* Accel data X-MSB register*/
#define BNO055_ACCEL_DATA_X_MSB_VALUEX_POS             (0)
#define BNO055_ACCEL_DATA_X_MSB_VALUEX_MSK             (0xFF)
#define BNO055_ACCEL_DATA_X_MSB_VALUEX_LEN             (8)
#define BNO055_ACCEL_DATA_X_MSB_VALUEX_REG             \
BNO055_ACCEL_DATA_X_MSB_ADDR

/* Accel data Y-LSB register*/
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY_POS             (0)
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY_MSK             (0xFF)
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY_LEN             (8)
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY_REG             \
BNO055_ACCEL_DATA_Y_LSB_ADDR

/* Accel data Y-MSB register*/
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY_POS             (0)
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY_MSK             (0xFF)
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY_LEN             (8)
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY_REG             \
BNO055_ACCEL_DATA_Y_MSB_ADDR

/* Accel data Z-LSB register*/
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ_POS		(0)
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ_MSK		(0xFF)
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ_LEN		(8)
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ_REG     \
BNO055_ACCEL_DATA_Z_LSB_ADDR

/* Accel data Z-MSB register*/
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ_POS		(0)
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ_MSK		(0xFF)
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ_LEN		(8)
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ_REG     \
BNO055_ACCEL_DATA_Z_MSB_ADDR

/* Mag data X-LSB register*/
#define BNO055_MAG_DATA_X_LSB_VALUEX_POS             (0)
#define BNO055_MAG_DATA_X_LSB_VALUEX_MSK             (0xFF)
#define BNO055_MAG_DATA_X_LSB_VALUEX_LEN             (8)
#define BNO055_MAG_DATA_X_LSB_VALUEX_REG             \
BNO055_MAG_DATA_X_LSB_ADDR

/* Mag data X-MSB register*/
#define BNO055_MAG_DATA_X_MSB_VALUEX_POS             (0)
#define BNO055_MAG_DATA_X_MSB_VALUEX_MSK             (0xFF)
#define BNO055_MAG_DATA_X_MSB_VALUEX_LEN             (8)
#define BNO055_MAG_DATA_X_MSB_VALUEX_REG             BNO055_MAG_DATA_X_MSB_ADDR

/* Mag data Y-LSB register*/
#define BNO055_MAG_DATA_Y_LSB_VALUEY_POS             (0)
#define BNO055_MAG_DATA_Y_LSB_VALUEY_MSK             (0xFF)
#define BNO055_MAG_DATA_Y_LSB_VALUEY_LEN             (8)
#define BNO055_MAG_DATA_Y_LSB_VALUEY_REG             BNO055_MAG_DATA_Y_LSB_ADDR

/* Mag data Y-MSB register*/
#define BNO055_MAG_DATA_Y_MSB_VALUEY_POS             (0)
#define BNO055_MAG_DATA_Y_MSB_VALUEY_MSK             (0xFF)
#define BNO055_MAG_DATA_Y_MSB_VALUEY_LEN             (8)
#define BNO055_MAG_DATA_Y_MSB_VALUEY_REG             BNO055_MAG_DATA_Y_MSB_ADDR

/* Mag data Z-LSB register*/
#define BNO055_MAG_DATA_Z_LSB_VALUEZ_POS             (0)
#define BNO055_MAG_DATA_Z_LSB_VALUEZ_MSK             (0xFF)
#define BNO055_MAG_DATA_Z_LSB_VALUEZ_LEN             (8)
#define BNO055_MAG_DATA_Z_LSB_VALUEZ_REG             BNO055_MAG_DATA_Z_LSB_ADDR

/* Mag data Z-MSB register*/
#define BNO055_MAG_DATA_Z_MSB_VALUEZ_POS             (0)
#define BNO055_MAG_DATA_Z_MSB_VALUEZ_MSK             (0xFF)
#define BNO055_MAG_DATA_Z_MSB_VALUEZ_LEN             (8)
#define BNO055_MAG_DATA_Z_MSB_VALUEZ_REG             BNO055_MAG_DATA_Z_MSB_ADDR

/* Gyro data X-LSB register*/
#define BNO055_GYRO_DATA_X_LSB_VALUEX_POS	(0)
#define BNO055_GYRO_DATA_X_LSB_VALUEX_MSK	(0xFF)
#define BNO055_GYRO_DATA_X_LSB_VALUEX_LEN	(8)
#define BNO055_GYRO_DATA_X_LSB_VALUEX_REG	BNO055_GYRO_DATA_X_LSB_ADDR

/* Gyro data X-MSB register*/
#define BNO055_GYRO_DATA_X_MSB_VALUEX_POS	(0)
#define BNO055_GYRO_DATA_X_MSB_VALUEX_MSK	(0xFF)
#define BNO055_GYRO_DATA_X_MSB_VALUEX_LEN	(8)
#define BNO055_GYRO_DATA_X_MSB_VALUEX_REG	BNO055_GYRO_DATA_X_MSB_ADDR

/* Gyro data Y-LSB register*/
#define BNO055_GYRO_DATA_Y_LSB_VALUEY_POS	(0)
#define BNO055_GYRO_DATA_Y_LSB_VALUEY_MSK	(0xFF)
#define BNO055_GYRO_DATA_Y_LSB_VALUEY_LEN	(8)
#define BNO055_GYRO_DATA_Y_LSB_VALUEY_REG	BNO055_GYRO_DATA_Y_LSB_ADDR

/* Gyro data Y-MSB register*/
#define BNO055_GYRO_DATA_Y_MSB_VALUEY_POS	(0)
#define BNO055_GYRO_DATA_Y_MSB_VALUEY_MSK	(0xFF)
#define BNO055_GYRO_DATA_Y_MSB_VALUEY_LEN	(8)
#define BNO055_GYRO_DATA_Y_MSB_VALUEY_REG	BNO055_GYRO_DATA_Y_MSB_ADDR

/* Gyro data Z-LSB register*/
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ_POS	(0)
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ_MSK	(0xFF)
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ_LEN	(8)
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ_REG	BNO055_GYRO_DATA_Z_LSB_ADDR

/* Gyro data Z-MSB register*/
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ_POS	(0)
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ_MSK	(0xFF)
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ_LEN	(8)
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ_REG	BNO055_GYRO_DATA_Z_MSB_ADDR

/* Euler data HEADING-LSB register*/
#define BNO055_EULER_H_LSB_VALUEH_POS   (0)
#define BNO055_EULER_H_LSB_VALUEH_MSK   (0xFF)
#define BNO055_EULER_H_LSB_VALUEH_LEN   (8)
#define BNO055_EULER_H_LSB_VALUEH_REG  BNO055_EULER_H_LSB_ADDR

/* Euler data HEADING-MSB register*/
#define BNO055_EULER_H_MSB_VALUEH_POS  (0)
#define BNO055_EULER_H_MSB_VALUEH_MSK  (0xFF)
#define BNO055_EULER_H_MSB_VALUEH_LEN  (8)
#define BNO055_EULER_H_MSB_VALUEH_REG  BNO055_EULER_H_MSB_ADDR

/* Euler data ROLL-LSB register*/
#define BNO055_EULER_R_LSB_VALUER_POS  (0)
#define BNO055_EULER_R_LSB_VALUER_MSK  (0xFF)
#define BNO055_EULER_R_LSB_VALUER_LEN  (8)
#define BNO055_EULER_R_LSB_VALUER_REG  BNO055_EULER_R_LSB_ADDR

/* Euler data ROLL-MSB register*/
#define BNO055_EULER_R_MSB_VALUER_POS  (0)
#define BNO055_EULER_R_MSB_VALUER_MSK  (0xFF)
#define BNO055_EULER_R_MSB_VALUER_LEN  (8)
#define BNO055_EULER_R_MSB_VALUER_REG  BNO055_EULER_R_MSB_ADDR

/* Euler data PITCH-LSB register*/
#define BNO055_EULER_P_LSB_VALUEP_POS  (0)
#define BNO055_EULER_P_LSB_VALUEP_MSK  (0xFF)
#define BNO055_EULER_P_LSB_VALUEP_LEN  (8)
#define BNO055_EULER_P_LSB_VALUEP_REG  BNO055_EULER_P_LSB_ADDR

/* Euler data HEADING-MSB register*/
#define BNO055_EULER_P_MSB_VALUEP_POS  (0)
#define BNO055_EULER_P_MSB_VALUEP_MSK  (0xFF)
#define BNO055_EULER_P_MSB_VALUEP_LEN  (8)
#define BNO055_EULER_P_MSB_VALUEP_REG  BNO055_EULER_P_MSB_ADDR

/* Quaternion data W-LSB register*/
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW_POS  (0)
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW_MSK  (0xFF)
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW_LEN  (8)
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW_REG  \
BNO055_QUATERNION_DATA_W_LSB_ADDR

/* Quaternion data W-MSB register*/
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW_POS  (0)
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW_MSK  (0xFF)
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW_LEN  (8)
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW_REG  \
BNO055_QUATERNION_DATA_W_MSB_ADDR

/* Quaternion data X-LSB register*/
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX_POS  (0)
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX_MSK  (0xFF)
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX_LEN  (8)
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX_REG  \
BNO055_QUATERNION_DATA_X_LSB_ADDR

/* Quaternion data X-MSB register*/
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX_POS  (0)
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX_MSK  (0xFF)
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX_LEN  (8)
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX_REG \
BNO055_QUATERNION_DATA_X_MSB_ADDR

/* Quaternion data Y-LSB register*/
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY_POS  (0)
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY_MSK  (0xFF)
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY_LEN  (8)
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY_REG \
BNO055_QUATERNION_DATA_Y_LSB_ADDR

/* Quaternion data Y-MSB register*/
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY_POS  (0)
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY_MSK  (0xFF)
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY_LEN  (8)
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY_REG  \
BNO055_QUATERNION_DATA_Y_MSB_ADDR

/* Quaternion data Z-LSB register*/
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ_POS  (0)
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ_MSK  (0xFF)
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ_LEN  (8)
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ_REG \
BNO055_QUATERNION_DATA_Z_LSB_ADDR

/* Quaternion data Z-MSB register*/
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ_POS  (0)
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ_MSK  (0xFF)
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ_LEN  (8)
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ_REG  \
BNO055_QUATERNION_DATA_Z_MSB_ADDR

/* Linear acceleration data X-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX_POS  (0)
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX_MSK  (0xFF)
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX_LEN  (8)
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX_REG  \
BNO055_LINEAR_ACCEL_DATA_X_LSB_ADDR

/* Linear acceleration data X-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX_POS  (0)
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX_MSK  (0xFF)
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX_LEN  (8)
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX_REG  \
BNO055_LINEAR_ACCEL_DATA_X_MSB_ADDR

/* Linear acceleration data Y-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY_POS  (0)
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY_MSK  (0xFF)
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY_LEN  (8)
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY_REG  \
BNO055_LINEAR_ACCEL_DATA_Y_LSB_ADDR

/* Linear acceleration data Y-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY_POS  (0)
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY_MSK  (0xFF)
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY_LEN  (8)
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY_REG  \
BNO055_LINEAR_ACCEL_DATA_Y_MSB_ADDR

/* Linear acceleration data Z-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ_POS  (0)
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ_MSK  (0xFF)
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ_LEN  (8)
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ_REG \
BNO055_LINEAR_ACCEL_DATA_Z_LSB_ADDR

/* Linear acceleration data Z-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ_POS  (0)
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ_MSK  (0xFF)
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ_LEN  (8)
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ_REG  \
BNO055_LINEAR_ACCEL_DATA_Z_MSB_ADDR

/* Gravity data X-LSB register*/
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX_POS  (0)
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX_MSK  (0xFF)
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX_LEN  (8)
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX_REG  \
BNO055_GRAVITY_DATA_X_LSB_ADDR

/* Gravity data X-MSB register*/
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX_POS  (0)
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX_MSK  (0xFF)
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX_LEN  (8)
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX_REG  \
BNO055_GRAVITY_DATA_X_MSB_ADDR

/* Gravity data Y-LSB register*/
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY_POS  (0)
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY_MSK  (0xFF)
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY_LEN  (8)
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY_REG  \
BNO055_GRAVITY_DATA_Y_LSB_ADDR

/* Gravity data Y-MSB register*/
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY_POS  (0)
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY_MSK  (0xFF)
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY_LEN  (8)
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY_REG  \
BNO055_GRAVITY_DATA_Y_MSB_ADDR

/* Gravity data Z-LSB register*/
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ_POS  (0)
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ_MSK  (0xFF)
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ_LEN  (8)
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ_REG  \
BNO055_GRAVITY_DATA_Z_LSB_ADDR

/* Gravity data Z-MSB register*/
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ_POS  (0)
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ_MSK  (0xFF)
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ_LEN  (8)
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ_REG  \
BNO055_GRAVITY_DATA_Z_MSB_ADDR

/* Temperature register*/
#define BNO055_TEMP_POS             (0)
#define BNO055_TEMP_MSK             (0xFF)
#define BNO055_TEMP_LEN             (8)
#define BNO055_TEMP_REG             BNO055_TEMP_ADDR

/*Mag_Calib status register*/
#define BNO055_MAG_CALIB_STAT_POS             (0)
#define BNO055_MAG_CALIB_STAT_MSK             (0X03)
#define BNO055_MAG_CALIB_STAT_LEN             (2)
#define BNO055_MAG_CALIB_STAT_REG             BNO055_CALIB_STAT_ADDR

/*Acc_Calib status register*/
#define BNO055_ACCEL_CALIB_STAT_POS             (2)
#define BNO055_ACCEL_CALIB_STAT_MSK             (0X0C)
#define BNO055_ACCEL_CALIB_STAT_LEN             (2)
#define BNO055_ACCEL_CALIB_STAT_REG             BNO055_CALIB_STAT_ADDR

/*Gyro_Calib status register*/
#define BNO055_GYRO_CALIB_STAT_POS             (4)
#define BNO055_GYRO_CALIB_STAT_MSK             (0X30)
#define BNO055_GYRO_CALIB_STAT_LEN             (2)
#define BNO055_GYRO_CALIB_STAT_REG             BNO055_CALIB_STAT_ADDR

/*Sys_Calib status register*/
#define BNO055_SYS_CALIB_STAT_POS             (6)
#define BNO055_SYS_CALIB_STAT_MSK             (0XC0)
#define BNO055_SYS_CALIB_STAT_LEN             (2)
#define BNO055_SYS_CALIB_STAT_REG             BNO055_CALIB_STAT_ADDR

/*ST_ACCEL register*/
#define BNO055_SELFTEST_ACCEL_POS             (0)
#define BNO055_SELFTEST_ACCEL_MSK             (0X01)
#define BNO055_SELFTEST_ACCEL_LEN             (1)
#define BNO055_SELFTEST_ACCEL_REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_MAG register*/
#define BNO055_SELFTEST_MAG_POS             (1)
#define BNO055_SELFTEST_MAG_MSK             (0X02)
#define BNO055_SELFTEST_MAG_LEN             (1)
#define BNO055_SELFTEST_MAG_REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_GYRO register*/
#define BNO055_SELFTEST_GYRO_POS             (2)
#define BNO055_SELFTEST_GYRO_MSK             (0X04)
#define BNO055_SELFTEST_GYRO_LEN             (1)
#define BNO055_SELFTEST_GYRO_REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_MCU register*/
#define BNO055_SELFTEST_MCU_POS             (3)
#define BNO055_SELFTEST_MCU_MSK             (0X08)
#define BNO055_SELFTEST_MCU_LEN             (1)
#define BNO055_SELFTEST_MCU_REG             BNO055_SELFTEST_RESULT_ADDR

/*Interrupt status registers*/
#define BNO055_INTR_STAT_GYRO_ANY_MOTION_POS		(2)
#define BNO055_INTR_STAT_GYRO_ANY_MOTION_MSK		(0X04)
#define BNO055_INTR_STAT_GYRO_ANY_MOTION_LEN		(1)
#define BNO055_INTR_STAT_GYRO_ANY_MOTION_REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_GYRO_HIGHRATE_POS		(3)
#define BNO055_INTR_STAT_GYRO_HIGHRATE_MSK		(0X08)
#define BNO055_INTR_STAT_GYRO_HIGHRATE_LEN		(1)
#define BNO055_INTR_STAT_GYRO_HIGHRATE_REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_HIGH_G_POS		(5)
#define BNO055_INTR_STAT_ACCEL_HIGH_G_MSK		(0X20)
#define BNO055_INTR_STAT_ACCEL_HIGH_G_LEN		(1)
#define BNO055_INTR_STAT_ACCEL_HIGH_G_REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_ANY_MOTION_POS		(6)
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION_MSK		(0X40)
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION_LEN		(1)
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION_REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_NO_MOTION_POS		(7)
#define BNO055_INTR_STAT_ACCEL_NO_MOTION_MSK		(0X80)
#define BNO055_INTR_STAT_ACCEL_NO_MOTION_LEN		(1)
#define BNO055_INTR_STAT_ACCEL_NO_MOTION_REG		BNO055_INTR_STAT_ADDR

/* system clock status register*/
#define BNO055_SYS_MAIN_CLK_POS		(0)
#define BNO055_SYS_MAIN_CLK_MSK		(0X10)
#define BNO055_SYS_MAIN_CLK_LEN		(1)
#define BNO055_SYS_MAIN_CLK_REG		BNO055_SYS_CLK_STAT_ADDR

/* System registers*/
#define BNO055_SYS_STAT_CODE_POS		(0)
#define BNO055_SYS_STAT_CODE_MSK		(0XFF)
#define BNO055_SYS_STAT_CODE_LEN		(8)
#define BNO055_SYS_STAT_CODE_REG		BNO055_SYS_STAT_ADDR

#define BNO055_SYS_ERROR_CODE_POS			(0)
#define BNO055_SYS_ERROR_CODE_MSK			(0XFF)
#define BNO055_SYS_ERROR_CODE_LEN			(8)
#define BNO055_SYS_ERROR_CODE_REG			BNO055_SYS_ERR_ADDR

/* Accel_Unit register*/
#define BNO055_ACCEL_UNIT_POS             (0)
#define BNO055_ACCEL_UNIT_MSK             (0X01)
#define BNO055_ACCEL_UNIT_LEN             (1)
#define BNO055_ACCEL_UNIT_REG             BNO055_UNIT_SEL_ADDR

/* Gyro_Unit register*/
#define BNO055_GYRO_UNIT_POS             (1)
#define BNO055_GYRO_UNIT_MSK             (0X02)
#define BNO055_GYRO_UNIT_LEN             (1)
#define BNO055_GYRO_UNIT_REG             BNO055_UNIT_SEL_ADDR

/* Euler_Unit register*/
#define BNO055_EULER_UNIT_POS             (2)
#define BNO055_EULER_UNIT_MSK             (0X04)
#define BNO055_EULER_UNIT_LEN             (1)
#define BNO055_EULER_UNIT_REG             BNO055_UNIT_SEL_ADDR

/* Tilt_Unit register*/
#define BNO055_TILT_UNIT_POS             (3)
#define BNO055_TILT_UNIT_MSK             (0X08)
#define BNO055_TILT_UNIT_LEN             (1)
#define BNO055_TILT_UNIT_REG             BNO055_UNIT_SEL_ADDR

/* Temperature_Unit register*/
#define BNO055_TEMP_UNIT_POS             (4)
#define BNO055_TEMP_UNIT_MSK             (0X10)
#define BNO055_TEMP_UNIT_LEN             (1)
#define BNO055_TEMP_UNIT_REG             BNO055_UNIT_SEL_ADDR

/* ORI android-windows register*/
#define BNO055_DATA_OUTPUT_FORMAT_POS             (7)
#define BNO055_DATA_OUTPUT_FORMAT_MSK             (0X80)
#define BNO055_DATA_OUTPUT_FORMAT_LEN             (1)
#define BNO055_DATA_OUTPUT_FORMAT_REG             BNO055_UNIT_SEL_ADDR
/*Operation Mode data register*/
#define BNO055_OPERATION_MODE_POS			(0)
#define BNO055_OPERATION_MODE_MSK			(0X0F)
#define BNO055_OPERATION_MODE_LEN			(4)
#define BNO055_OPERATION_MODE_REG			BNO055_OPR_MODE_ADDR
/* Power Mode register*/
#define BNO055_POWER_MODE_POS             (0)
#define BNO055_POWER_MODE_MSK             (0X03)
#define BNO055_POWER_MODE_LEN             (2)
#define BNO055_POWER_MODE_REG             BNO055_PWR_MODE_ADDR

/*Self Test register*/
#define BNO055_SELFTEST_POS			(0)
#define BNO055_SELFTEST_MSK			(0X01)
#define BNO055_SELFTEST_LEN			(1)
#define BNO055_SELFTEST_REG			BNO055_SYS_TRIGGER_ADDR

/* RST_SYS register*/
#define BNO055_SYS_RST_POS             (5)
#define BNO055_SYS_RST_MSK             (0X20)
#define BNO055_SYS_RST_LEN             (1)
#define BNO055_SYS_RST_REG             BNO055_SYS_TRIGGER_ADDR

/* RST_INT register*/
#define BNO055_INTR_RST_POS             (6)
#define BNO055_INTR_RST_MSK             (0X40)
#define BNO055_INTR_RST_LEN             (1)
#define BNO055_INTR_RST_REG             BNO055_SYS_TRIGGER_ADDR

/* CLK_SRC register*/
#define BNO055_CLK_SRC_POS             (7)
#define BNO055_CLK_SRC_MSK             (0X80)
#define BNO055_CLK_SRC_LEN             (1)
#define BNO055_CLK_SRC_REG             BNO055_SYS_TRIGGER_ADDR

/* Temp source register*/
#define BNO055_TEMP_SOURCE_POS		(0)
#define BNO055_TEMP_SOURCE_MSK		(0X03)
#define BNO055_TEMP_SOURCE_LEN		(2)
#define BNO055_TEMP_SOURCE_REG		BNO055_TEMP_SOURCE_ADDR

/* Axis remap value register*/
#define BNO055_REMAP_AXIS_VALUE_POS		(0)
#define BNO055_REMAP_AXIS_VALUE_MSK		(0X3F)
#define BNO055_REMAP_AXIS_VALUE_LEN		(6)
#define BNO055_REMAP_AXIS_VALUE_REG		BNO055_AXIS_MAP_CONFIG_ADDR

/* Axis sign value register*/
#define BNO055_REMAP_Z_SIGN_POS		(0)
#define BNO055_REMAP_Z_SIGN_MSK		(0X01)
#define BNO055_REMAP_Z_SIGN_LEN		(1)
#define BNO055_REMAP_Z_SIGN_REG		BNO055_AXIS_MAP_SIGN_ADDR

#define BNO055_REMAP_Y_SIGN_POS		(1)
#define BNO055_REMAP_Y_SIGN_MSK		(0X02)
#define BNO055_REMAP_Y_SIGN_LEN		(1)
#define BNO055_REMAP_Y_SIGN_REG		BNO055_AXIS_MAP_SIGN_ADDR

#define BNO055_REMAP_X_SIGN_POS		(2)
#define BNO055_REMAP_X_SIGN_MSK		(0X04)
#define BNO055_REMAP_X_SIGN_LEN		(1)
#define BNO055_REMAP_X_SIGN_REG		BNO055_AXIS_MAP_SIGN_ADDR

/* Soft Iron Calibration matrix register*/
#define BNO055_SIC_MATRIX_0_LSB_POS		(0)
#define BNO055_SIC_MATRIX_0_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_0_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_0_LSB_REG		BNO055_SIC_MATRIX_0_LSB_ADDR

#define BNO055_SIC_MATRIX_0_MSB_POS		(0)
#define BNO055_SIC_MATRIX_0_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_0_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_0_MSB_REG		BNO055_SIC_MATRIX_0_MSB_ADDR

#define BNO055_SIC_MATRIX_1_LSB_POS		(0)
#define BNO055_SIC_MATRIX_1_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_1_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_1_LSB_REG		BNO055_SIC_MATRIX_1_LSB_ADDR

#define BNO055_SIC_MATRIX_1_MSB_POS		(0)
#define BNO055_SIC_MATRIX_1_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_1_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_1_MSB_REG		BNO055_SIC_MATRIX_1_MSB_ADDR

#define BNO055_SIC_MATRIX_2_LSB_POS		(0)
#define BNO055_SIC_MATRIX_2_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_2_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_2_LSB_REG		BNO055_SIC_MATRIX_2_LSB_ADDR

#define BNO055_SIC_MATRIX_2_MSB_POS		(0)
#define BNO055_SIC_MATRIX_2_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_2_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_2_MSB_REG		BNO055_SIC_MATRIX_2_MSB_ADDR

#define BNO055_SIC_MATRIX_3_LSB_POS		(0)
#define BNO055_SIC_MATRIX_3_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_3_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_3_LSB_REG		BNO055_SIC_MATRIX_3_LSB_ADDR

#define BNO055_SIC_MATRIX_3_MSB_POS		(0)
#define BNO055_SIC_MATRIX_3_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_3_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_3_MSB_REG		BNO055_SIC_MATRIX_3_MSB_ADDR

#define BNO055_SIC_MATRIX_4_LSB_POS		(0)
#define BNO055_SIC_MATRIX_4_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_4_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_4_LSB_REG		BNO055_SIC_MATRIX_4_LSB_ADDR

#define BNO055_SIC_MATRIX_4_MSB_POS		(0)
#define BNO055_SIC_MATRIX_4_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_4_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_4_MSB_REG		BNO055_SIC_MATRIX_4_MSB_ADDR

#define BNO055_SIC_MATRIX_5_LSB_POS		(0)
#define BNO055_SIC_MATRIX_5_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_5_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_5_LSB_REG		BNO055_SIC_MATRIX_5_LSB_ADDR

#define BNO055_SIC_MATRIX_5_MSB_POS		(0)
#define BNO055_SIC_MATRIX_5_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_5_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_5_MSB_REG		BNO055_SIC_MATRIX_5_MSB_ADDR

#define BNO055_SIC_MATRIX_6_LSB_POS		(0)
#define BNO055_SIC_MATRIX_6_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_6_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_6_LSB_REG		BNO055_SIC_MATRIX_6_LSB_ADDR

#define BNO055_SIC_MATRIX_6_MSB_POS		(0)
#define BNO055_SIC_MATRIX_6_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_6_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_6_MSB_REG		BNO055_SIC_MATRIX_6_MSB_ADDR

#define BNO055_SIC_MATRIX_7_LSB_POS		(0)
#define BNO055_SIC_MATRIX_7_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_7_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_7_LSB_REG		BNO055_SIC_MATRIX_7_LSB_ADDR

#define BNO055_SIC_MATRIX_7_MSB_POS		(0)
#define BNO055_SIC_MATRIX_7_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_7_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_7_MSB_REG		BNO055_SIC_MATRIX_7_MSB_ADDR

#define BNO055_SIC_MATRIX_8_LSB_POS		(0)
#define BNO055_SIC_MATRIX_8_LSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_8_LSB_LEN		(8)
#define BNO055_SIC_MATRIX_8_LSB_REG		BNO055_SIC_MATRIX_8_LSB_ADDR

#define BNO055_SIC_MATRIX_8_MSB_POS		(0)
#define BNO055_SIC_MATRIX_8_MSB_MSK		(0XFF)
#define BNO055_SIC_MATRIX_8_MSB_LEN		(8)
#define BNO055_SIC_MATRIX_8_MSB_REG		BNO055_SIC_MATRIX_8_MSB_ADDR

/*Accel Offset registers*/
#define BNO055_ACCEL_OFFSET_X_LSB_POS		(0)
#define BNO055_ACCEL_OFFSET_X_LSB_MSK		(0XFF)
#define BNO055_ACCEL_OFFSET_X_LSB_LEN		(8)
#define BNO055_ACCEL_OFFSET_X_LSB_REG		BNO055_ACCEL_OFFSET_X_LSB_ADDR

#define BNO055_ACCEL_OFFSET_X_MSB_POS		(0)
#define BNO055_ACCEL_OFFSET_X_MSB_MSK		(0XFF)
#define BNO055_ACCEL_OFFSET_X_MSB_LEN		(8)
#define BNO055_ACCEL_OFFSET_X_MSB_REG		BNO055_ACCEL_OFFSET_X_MSB_ADDR

#define BNO055_ACCEL_OFFSET_Y_LSB_POS		(0)
#define BNO055_ACCEL_OFFSET_Y_LSB_MSK		(0XFF)
#define BNO055_ACCEL_OFFSET_Y_LSB_LEN		(8)
#define BNO055_ACCEL_OFFSET_Y_LSB_REG		BNO055_ACCEL_OFFSET_Y_LSB_ADDR

#define BNO055_ACCEL_OFFSET_Y_MSB_POS		(0)
#define BNO055_ACCEL_OFFSET_Y_MSB_MSK		(0XFF)
#define BNO055_ACCEL_OFFSET_Y_MSB_LEN		(8)
#define BNO055_ACCEL_OFFSET_Y_MSB_REG		BNO055_ACCEL_OFFSET_Y_MSB_ADDR

#define BNO055_ACCEL_OFFSET_Z_LSB_POS		(0)
#define BNO055_ACCEL_OFFSET_Z_LSB_MSK		(0XFF)
#define BNO055_ACCEL_OFFSET_Z_LSB_LEN		(8)
#define BNO055_ACCEL_OFFSET_Z_LSB_REG		BNO055_ACCEL_OFFSET_Z_LSB_ADDR

#define BNO055_ACCEL_OFFSET_Z_MSB_POS		(0)
#define BNO055_ACCEL_OFFSET_Z_MSB_MSK		(0XFF)
#define BNO055_ACCEL_OFFSET_Z_MSB_LEN		(8)
#define BNO055_ACCEL_OFFSET_Z_MSB_REG		BNO055_ACCEL_OFFSET_Z_MSB_ADDR

/*Mag Offset registers*/
#define BNO055_MAG_OFFSET_X_LSB_POS		(0)
#define BNO055_MAG_OFFSET_X_LSB_MSK		(0XFF)
#define BNO055_MAG_OFFSET_X_LSB_LEN		(8)
#define BNO055_MAG_OFFSET_X_LSB_REG		BNO055_MAG_OFFSET_X_LSB_ADDR

#define BNO055_MAG_OFFSET_X_MSB_POS		(0)
#define BNO055_MAG_OFFSET_X_MSB_MSK		(0XFF)
#define BNO055_MAG_OFFSET_X_MSB_LEN		(8)
#define BNO055_MAG_OFFSET_X_MSB_REG		BNO055_MAG_OFFSET_X_MSB_ADDR

#define BNO055_MAG_OFFSET_Y_LSB_POS		(0)
#define BNO055_MAG_OFFSET_Y_LSB_MSK		(0XFF)
#define BNO055_MAG_OFFSET_Y_LSB_LEN		(8)
#define BNO055_MAG_OFFSET_Y_LSB_REG		BNO055_MAG_OFFSET_Y_LSB_ADDR

#define BNO055_MAG_OFFSET_Y_MSB_POS		(0)
#define BNO055_MAG_OFFSET_Y_MSB_MSK		(0XFF)
#define BNO055_MAG_OFFSET_Y_MSB_LEN		(8)
#define BNO055_MAG_OFFSET_Y_MSB_REG		BNO055_MAG_OFFSET_Y_MSB_ADDR

#define BNO055_MAG_OFFSET_Z_LSB_POS		(0)
#define BNO055_MAG_OFFSET_Z_LSB_MSK		(0XFF)
#define BNO055_MAG_OFFSET_Z_LSB_LEN		(8)
#define BNO055_MAG_OFFSET_Z_LSB_REG		BNO055_MAG_OFFSET_Z_LSB_ADDR

#define BNO055_MAG_OFFSET_Z_MSB_POS		(0)
#define BNO055_MAG_OFFSET_Z_MSB_MSK		(0XFF)
#define BNO055_MAG_OFFSET_Z_MSB_LEN		(8)
#define BNO055_MAG_OFFSET_Z_MSB_REG		BNO055_MAG_OFFSET_Z_MSB_ADDR

/* Gyro Offset registers*/
#define BNO055_GYRO_OFFSET_X_LSB_POS		(0)
#define BNO055_GYRO_OFFSET_X_LSB_MSK		(0XFF)
#define BNO055_GYRO_OFFSET_X_LSB_LEN		(8)
#define BNO055_GYRO_OFFSET_X_LSB_REG		BNO055_GYRO_OFFSET_X_LSB_ADDR

#define BNO055_GYRO_OFFSET_X_MSB_POS		(0)
#define BNO055_GYRO_OFFSET_X_MSB_MSK		(0XFF)
#define BNO055_GYRO_OFFSET_X_MSB_LEN		(8)
#define BNO055_GYRO_OFFSET_X_MSB_REG		BNO055_GYRO_OFFSET_X_MSB_ADDR

#define BNO055_GYRO_OFFSET_Y_LSB_POS		(0)
#define BNO055_GYRO_OFFSET_Y_LSB_MSK		(0XFF)
#define BNO055_GYRO_OFFSET_Y_LSB_LEN		(8)
#define BNO055_GYRO_OFFSET_Y_LSB_REG		BNO055_GYRO_OFFSET_Y_LSB_ADDR

#define BNO055_GYRO_OFFSET_Y_MSB_POS		(0)
#define BNO055_GYRO_OFFSET_Y_MSB_MSK		(0XFF)
#define BNO055_GYRO_OFFSET_Y_MSB_LEN		(8)
#define BNO055_GYRO_OFFSET_Y_MSB_REG		BNO055_GYRO_OFFSET_Y_MSB_ADDR

#define BNO055_GYRO_OFFSET_Z_LSB_POS		(0)
#define BNO055_GYRO_OFFSET_Z_LSB_MSK		(0XFF)
#define BNO055_GYRO_OFFSET_Z_LSB_LEN		(8)
#define BNO055_GYRO_OFFSET_Z_LSB_REG		BNO055_GYRO_OFFSET_Z_LSB_ADDR

#define BNO055_GYRO_OFFSET_Z_MSB_POS		(0)
#define BNO055_GYRO_OFFSET_Z_MSB_MSK		(0XFF)
#define BNO055_GYRO_OFFSET_Z_MSB_LEN		(8)
#define BNO055_GYRO_OFFSET_Z_MSB_REG		BNO055_GYRO_OFFSET_Z_MSB_ADDR

/* Radius register definition*/
#define BNO055_ACCEL_RADIUS_LSB_POS		(0)
#define BNO055_ACCEL_RADIUS_LSB_MSK		(0XFF)
#define BNO055_ACCEL_RADIUS_LSB_LEN		(8)
#define BNO055_ACCEL_RADIUS_LSB_REG		BNO055_ACCEL_RADIUS_LSB_ADDR

#define BNO055_ACCEL_RADIUS_MSB_POS		(0)
#define BNO055_ACCEL_RADIUS_MSB_MSK		(0XFF)
#define BNO055_ACCEL_RADIUS_MSB_LEN		(8)
#define BNO055_ACCEL_RADIUS_MSB_REG		BNO055_ACCEL_RADIUS_MSB_ADDR

#define BNO055_MAG_RADIUS_LSB_POS		(0)
#define BNO055_MAG_RADIUS_LSB_MSK		(0XFF)
#define BNO055_MAG_RADIUS_LSB_LEN		(8)
#define BNO055_MAG_RADIUS_LSB_REG		BNO055_MAG_RADIUS_LSB_ADDR

#define BNO055_MAG_RADIUS_MSB_POS		(0)
#define BNO055_MAG_RADIUS_MSB_MSK		(0XFF)
#define BNO055_MAG_RADIUS_MSB_LEN		(8)
#define BNO055_MAG_RADIUS_MSB_REG		BNO055_MAG_RADIUS_MSB_ADDR

/* PAGE0 DATA REGISTERS DEFINITION END*/
/*************************************************/
/**\name PAGE1 DATA REGISTERS DEFINITION   */
/*************************************************/
/* Configuration registers*/
/* Accel range configuration register*/
#define BNO055_ACCEL_RANGE_POS		(0)
#define BNO055_ACCEL_RANGE_MSK		(0X03)
#define BNO055_ACCEL_RANGE_LEN		(2)
#define BNO055_ACCEL_RANGE_REG		BNO055_ACCEL_CONFIG_ADDR

/* Accel bandwidth configuration register*/
#define BNO055_ACCEL_BW_POS			(2)
#define BNO055_ACCEL_BW_MSK			(0X1C)
#define BNO055_ACCEL_BW_LEN			(3)
#define BNO055_ACCEL_BW_REG			BNO055_ACCEL_CONFIG_ADDR

/* Accel power mode configuration register*/
#define BNO055_ACCEL_POWER_MODE_POS		(5)
#define BNO055_ACCEL_POWER_MODE_MSK		(0XE0)
#define BNO055_ACCEL_POWER_MODE_LEN		(3)
#define BNO055_ACCEL_POWER_MODE_REG		BNO055_ACCEL_CONFIG_ADDR

/* Mag data output rate configuration register*/
#define BNO055_MAG_DATA_OUTPUT_RATE_POS		(0)
#define BNO055_MAG_DATA_OUTPUT_RATE_MSK		(0X07)
#define BNO055_MAG_DATA_OUTPUT_RATE_LEN		(3)
#define BNO055_MAG_DATA_OUTPUT_RATE_REG		BNO055_MAG_CONFIG_ADDR

/* Mag operation mode configuration register*/
#define BNO055_MAG_OPERATION_MODE_POS		(3)
#define BNO055_MAG_OPERATION_MODE_MSK		(0X18)
#define BNO055_MAG_OPERATION_MODE_LEN		(2)
#define BNO055_MAG_OPERATION_MODE_REG		BNO055_MAG_CONFIG_ADDR

/* Mag power mode configuration register*/
#define BNO055_MAG_POWER_MODE_POS		(5)
#define BNO055_MAG_POWER_MODE_MSK		(0X60)
#define BNO055_MAG_POWER_MODE_LEN		(2)
#define BNO055_MAG_POWER_MODE_REG		BNO055_MAG_CONFIG_ADDR

/* Gyro range configuration register*/
#define BNO055_GYRO_RANGE_POS		(0)
#define BNO055_GYRO_RANGE_MSK		(0X07)
#define BNO055_GYRO_RANGE_LEN		(3)
#define BNO055_GYRO_RANGE_REG		BNO055_GYRO_CONFIG_ADDR

/* Gyro bandwidth configuration register*/
#define BNO055_GYRO_BW_POS		(3)
#define BNO055_GYRO_BW_MSK		(0X38)
#define BNO055_GYRO_BW_LEN		(3)
#define BNO055_GYRO_BW_REG		BNO055_GYRO_CONFIG_ADDR

/* Gyro power mode configuration register*/
#define BNO055_GYRO_POWER_MODE_POS		(0)
#define BNO055_GYRO_POWER_MODE_MSK		(0X07)
#define BNO055_GYRO_POWER_MODE_LEN		(3)
#define BNO055_GYRO_POWER_MODE_REG		BNO055_GYRO_MODE_CONFIG_ADDR

/* Sleep configuration registers*/
/* Accel sleep mode configuration register*/
#define BNO055_ACCEL_SLEEP_MODE_POS		(0)
#define BNO055_ACCEL_SLEEP_MODE_MSK		(0X01)
#define BNO055_ACCEL_SLEEP_MODE_LEN		(1)
#define BNO055_ACCEL_SLEEP_MODE_REG		BNO055_ACCEL_SLEEP_CONFIG_ADDR

/* Accel sleep duration configuration register*/
#define BNO055_ACCEL_SLEEP_DURN_POS		(1)
#define BNO055_ACCEL_SLEEP_DURN_MSK		(0X1E)
#define BNO055_ACCEL_SLEEP_DURN_LEN		(4)
#define BNO055_ACCEL_SLEEP_DURN_REG		BNO055_ACCEL_SLEEP_CONFIG_ADDR

/* Gyro sleep duration configuration register*/
#define BNO055_GYRO_SLEEP_DURN_POS		(0)
#define BNO055_GYRO_SLEEP_DURN_MSK		(0X07)
#define BNO055_GYRO_SLEEP_DURN_LEN		(3)
#define BNO055_GYRO_SLEEP_DURN_REG		BNO055_GYRO_SLEEP_CONFIG_ADDR

/* Gyro auto sleep duration configuration register*/
#define BNO055_GYRO_AUTO_SLEEP_DURN_POS		(3)
#define BNO055_GYRO_AUTO_SLEEP_DURN_MSK		(0X38)
#define BNO055_GYRO_AUTO_SLEEP_DURN_LEN		(3)
#define BNO055_GYRO_AUTO_SLEEP_DURN_REG		BNO055_GYRO_SLEEP_CONFIG_ADDR

/* Mag sleep mode configuration register*/
#define BNO055_MAG_SLEEP_MODE_POS		(0)
#define BNO055_MAG_SLEEP_MODE_MSK		(0X01)
#define BNO055_MAG_SLEEP_MODE_LEN		(1)
#define BNO055_MAG_SLEEP_MODE_REG		BNO055_MAG_SLEEP_CONFIG_ADDR

/* Mag sleep duration configuration register*/
#define BNO055_MAG_SLEEP_DURN_POS		(1)
#define BNO055_MAG_SLEEP_DURN_MSK		(0X1E)
#define BNO055_MAG_SLEEP_DURN_LEN		(4)
#define BNO055_MAG_SLEEP_DURN_REG		BNO055_MAG_SLEEP_CONFIG_ADDR

/* Interrupt registers*/
/* Gyro any motion interrupt msk register*/
#define BNO055_GYRO_ANY_MOTION_INTR_MASK_POS		(2)
#define BNO055_GYRO_ANY_MOTION_INTR_MASK_MSK		(0X04)
#define BNO055_GYRO_ANY_MOTION_INTR_MASK_LEN		(1)
#define BNO055_GYRO_ANY_MOTION_INTR_MASK_REG		BNO055_INT_MASK_ADDR

/* Gyro high rate interrupt msk register*/
#define BNO055_GYRO_HIGHRATE_INTR_MASK_POS		(3)
#define BNO055_GYRO_HIGHRATE_INTR_MASK_MSK		(0X08)
#define BNO055_GYRO_HIGHRATE_INTR_MASK_LEN		(1)
#define BNO055_GYRO_HIGHRATE_INTR_MASK_REG		BNO055_INT_MASK_ADDR

/* Accel high g interrupt msk register*/
#define BNO055_ACCEL_HIGH_G_INTR_MASK_POS		(5)
#define BNO055_ACCEL_HIGH_G_INTR_MASK_MSK		(0X20)
#define BNO055_ACCEL_HIGH_G_INTR_MASK_LEN		(1)
#define BNO055_ACCEL_HIGH_G_INTR_MASK_REG		BNO055_INT_MASK_ADDR

/* Accel any motion interrupt msk register*/
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK_POS		(6)
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK_MSK		(0X40)
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK_LEN		(1)
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK_REG		BNO055_INT_MASK_ADDR

/* Accel any motion interrupt msk register*/
#define BNO055_ACCEL_NO_MOTION_INTR_MASK_POS		(7)
#define BNO055_ACCEL_NO_MOTION_INTR_MASK_MSK		(0X80)
#define BNO055_ACCEL_NO_MOTION_INTR_MASK_LEN		(1)
#define BNO055_ACCEL_NO_MOTION_INTR_MASK_REG		BNO055_INT_MASK_ADDR

/* Gyro any motion interrupt register*/
#define BNO055_GYRO_ANY_MOTION_INTR_POS		(2)
#define BNO055_GYRO_ANY_MOTION_INTR_MSK		(0X04)
#define BNO055_GYRO_ANY_MOTION_INTR_LEN		(1)
#define BNO055_GYRO_ANY_MOTION_INTR_REG		BNO055_INT_ADDR

/* Gyro high rate interrupt register*/
#define BNO055_GYRO_HIGHRATE_INTR_POS		(3)
#define BNO055_GYRO_HIGHRATE_INTR_MSK		(0X08)
#define BNO055_GYRO_HIGHRATE_INTR_LEN		(1)
#define BNO055_GYRO_HIGHRATE_INTR_REG		BNO055_INT_ADDR

/* Accel high g interrupt register*/
#define BNO055_ACCEL_HIGH_G_INTR_POS		(5)
#define BNO055_ACCEL_HIGH_G_INTR_MSK		(0X20)
#define BNO055_ACCEL_HIGH_G_INTR_LEN		(1)
#define BNO055_ACCEL_HIGH_G_INTR_REG		BNO055_INT_ADDR

/* Accel any motion interrupt register*/
#define BNO055_ACCEL_ANY_MOTION_INTR_POS		(6)
#define BNO055_ACCEL_ANY_MOTION_INTR_MSK		(0X40)
#define BNO055_ACCEL_ANY_MOTION_INTR_LEN		(1)
#define BNO055_ACCEL_ANY_MOTION_INTR_REG		BNO055_INT_ADDR

/*Accel any motion interrupt register*/
#define BNO055_ACCEL_NO_MOTION_INTR_POS		(7)
#define BNO055_ACCEL_NO_MOTION_INTR_MSK		(0X80)
#define BNO055_ACCEL_NO_MOTION_INTR_LEN		(1)
#define BNO055_ACCEL_NO_MOTION_INTR_REG		BNO055_INT_ADDR

/*Accel any motion threshold setting*/
#define BNO055_ACCEL_ANY_MOTION_THRES_POS	(0)
#define BNO055_ACCEL_ANY_MOTION_THRES_MSK	(0XFF)
#define BNO055_ACCEL_ANY_MOTION_THRES_LEN	(8)
#define BNO055_ACCEL_ANY_MOTION_THRES_REG  BNO055_ACCEL_ANY_MOTION_THRES_ADDR

/*Accel interrupt setting register*/
#define BNO055_ACCEL_ANY_MOTION_DURN_SET_POS		(0)
#define BNO055_ACCEL_ANY_MOTION_DURN_SET_MSK		(0X03)
#define BNO055_ACCEL_ANY_MOTION_DURN_SET_LEN		(2)
#define BNO055_ACCEL_ANY_MOTION_DURN_SET_REG  BNO055_ACCEL_INTR_SETTINGS_ADDR

/* Accel AM/NM axis selection register*/
#define BNO055_ACCEL_ANY_MOTION_X_AXIS_POS		(2)
#define BNO055_ACCEL_ANY_MOTION_X_AXIS_MSK		(0X04)
#define BNO055_ACCEL_ANY_MOTION_X_AXIS_LEN		(1)
#define BNO055_ACCEL_ANY_MOTION_X_AXIS_REG  BNO055_ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_ANY_MOTION_Y_AXIS_POS		(3)
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS_MSK		(0X08)
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS_LEN		(1)
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS_REG  BNO055_ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_ANY_MOTION_Z_AXIS_POS		(4)
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS_MSK		(0X10)
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS_LEN		(1)
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS_REG  BNO055_ACCEL_INTR_SETTINGS_ADDR

/* Accel high g axis selection register*/
#define BNO055_ACCEL_HIGH_G_X_AXIS_POS		(5)
#define BNO055_ACCEL_HIGH_G_X_AXIS_MSK		(0X20)
#define BNO055_ACCEL_HIGH_G_X_AXIS_LEN		(1)
#define BNO055_ACCEL_HIGH_G_X_AXIS_REG		BNO055_ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_HIGH_G_Y_AXIS_POS		(6)
#define BNO055_ACCEL_HIGH_G_Y_AXIS_MSK		(0X40)
#define BNO055_ACCEL_HIGH_G_Y_AXIS_LEN		(1)
#define BNO055_ACCEL_HIGH_G_Y_AXIS_REG		BNO055_ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_HIGH_G_Z_AXIS_POS		(7)
#define BNO055_ACCEL_HIGH_G_Z_AXIS_MSK		(0X80)
#define BNO055_ACCEL_HIGH_G_Z_AXIS_LEN		(1)
#define BNO055_ACCEL_HIGH_G_Z_AXIS_REG		BNO055_ACCEL_INTR_SETTINGS_ADDR

/* Accel High g duration setting register*/
#define BNO055_ACCEL_HIGH_G_DURN_POS		(0)
#define BNO055_ACCEL_HIGH_G_DURN_MSK		(0XFF)
#define BNO055_ACCEL_HIGH_G_DURN_LEN		(8)
#define BNO055_ACCEL_HIGH_G_DURN_REG		BNO055_ACCEL_HIGH_G_DURN_ADDR

/* Accel High g threshold setting register*/
#define BNO055_ACCEL_HIGH_G_THRES_POS		(0)
#define BNO055_ACCEL_HIGH_G_THRES_MSK		(0XFF)
#define BNO055_ACCEL_HIGH_G_THRES_LEN		(8)
#define BNO055_ACCEL_HIGH_G_THRES_REG		BNO055_ACCEL_HIGH_G_THRES_ADDR

/* Accel no/slow motion threshold setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES_POS		(0)
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES_MSK		(0XFF)
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES_LEN		(8)
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES_REG		\
BNO055_ACCEL_NO_MOTION_THRES_ADDR

/* Accel no/slow motion enable setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE_POS		(0)
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE_MSK		(0X01)
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE_LEN		(1)
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE_REG BNO055_ACCEL_NO_MOTION_SET_ADDR

/* Accel no/slow motion duration setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN_POS		(1)
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN_MSK		(0X7E)
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN_LEN		(6)
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN_REG   BNO055_ACCEL_NO_MOTION_SET_ADDR

/*Gyro interrupt setting register*/
/*Gyro any motion axis setting*/
#define BNO055_GYRO_ANY_MOTION_X_AXIS_POS		(0)
#define BNO055_GYRO_ANY_MOTION_X_AXIS_MSK		(0X01)
#define BNO055_GYRO_ANY_MOTION_X_AXIS_LEN		(1)
#define BNO055_GYRO_ANY_MOTION_X_AXIS_REG    BNO055_GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_ANY_MOTION_Y_AXIS_POS		(1)
#define BNO055_GYRO_ANY_MOTION_Y_AXIS_MSK		(0X02)
#define BNO055_GYRO_ANY_MOTION_Y_AXIS_LEN		(1)
#define BNO055_GYRO_ANY_MOTION_Y_AXIS_REG    BNO055_GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_ANY_MOTION_Z_AXIS_POS		(2)
#define BNO055_GYRO_ANY_MOTION_Z_AXIS_MSK		(0X04)
#define BNO055_GYRO_ANY_MOTION_Z_AXIS_LEN		(1)
#define BNO055_GYRO_ANY_MOTION_Z_AXIS_REG     BNO055_GYRO_INTR_SETING_ADDR

/*Gyro high rate axis setting*/
#define BNO055_GYRO_HIGHRATE_X_AXIS_POS		(3)
#define BNO055_GYRO_HIGHRATE_X_AXIS_MSK		(0X08)
#define BNO055_GYRO_HIGHRATE_X_AXIS_LEN		(1)
#define BNO055_GYRO_HIGHRATE_X_AXIS_REG		BNO055_GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_Y_AXIS_POS		(4)
#define BNO055_GYRO_HIGHRATE_Y_AXIS_MSK		(0X10)
#define BNO055_GYRO_HIGHRATE_Y_AXIS_LEN		(1)
#define BNO055_GYRO_HIGHRATE_Y_AXIS_REG		BNO055_GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_Z_AXIS_POS		(5)
#define BNO055_GYRO_HIGHRATE_Z_AXIS_MSK		(0X20)
#define BNO055_GYRO_HIGHRATE_Z_AXIS_LEN		(1)
#define BNO055_GYRO_HIGHRATE_Z_AXIS_REG		BNO055_GYRO_INTR_SETING_ADDR

/* Gyro filter setting*/
#define BNO055_GYRO_ANY_MOTION_FILTER_POS		(6)
#define BNO055_GYRO_ANY_MOTION_FILTER_MSK		(0X40)
#define BNO055_GYRO_ANY_MOTION_FILTER_LEN		(1)
#define BNO055_GYRO_ANY_MOTION_FILTER_REG    BNO055_GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_FILTER_POS		(7)
#define BNO055_GYRO_HIGHRATE_FILTER_MSK		(0X80)
#define BNO055_GYRO_HIGHRATE_FILTER_LEN		(1)
#define BNO055_GYRO_HIGHRATE_FILTER_REG		BNO055_GYRO_INTR_SETING_ADDR

/* Gyro high rate X axis settings*/
#define BNO055_GYRO_HIGHRATE_X_THRES_POS		(0)
#define BNO055_GYRO_HIGHRATE_X_THRES_MSK		(0X1F)
#define BNO055_GYRO_HIGHRATE_X_THRES_LEN		(5)
#define BNO055_GYRO_HIGHRATE_X_THRES_REG    BNO055_GYRO_HIGHRATE_X_SET_ADDR

#define BNO055_GYRO_HIGHRATE_X_HYST_POS		(5)
#define BNO055_GYRO_HIGHRATE_X_HYST_MSK		(0X60)
#define BNO055_GYRO_HIGHRATE_X_HYST_LEN		(2)
#define BNO055_GYRO_HIGHRATE_X_HYST_REG		BNO055_GYRO_HIGHRATE_X_SET_ADDR

#define BNO055_GYRO_HIGHRATE_X_DURN_POS		(0)
#define BNO055_GYRO_HIGHRATE_X_DURN_MSK		(0XFF)
#define BNO055_GYRO_HIGHRATE_X_DURN_LEN		(8)
#define BNO055_GYRO_HIGHRATE_X_DURN_REG		BNO055_GYRO_DURN_X_ADDR

/* Gyro high rate Y axis settings*/
#define BNO055_GYRO_HIGHRATE_Y_THRES_POS		(0)
#define BNO055_GYRO_HIGHRATE_Y_THRES_MSK		(0X1F)
#define BNO055_GYRO_HIGHRATE_Y_THRES_LEN		(5)
#define BNO055_GYRO_HIGHRATE_Y_THRES_REG    BNO055_GYRO_HIGHRATE_Y_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Y_HYST_POS		(5)
#define BNO055_GYRO_HIGHRATE_Y_HYST_MSK		(0X60)
#define BNO055_GYRO_HIGHRATE_Y_HYST_LEN		(2)
#define BNO055_GYRO_HIGHRATE_Y_HYST_REG		BNO055_GYRO_HIGHRATE_Y_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Y_DURN_POS		(0)
#define BNO055_GYRO_HIGHRATE_Y_DURN_MSK		(0XFF)
#define BNO055_GYRO_HIGHRATE_Y_DURN_LEN		(8)
#define BNO055_GYRO_HIGHRATE_Y_DURN_REG		BNO055_GYRO_DURN_Y_ADDR

/* Gyro high rate Z axis settings*/
#define BNO055_GYRO_HIGHRATE_Z_THRES_POS		(0)
#define BNO055_GYRO_HIGHRATE_Z_THRES_MSK		(0X1F)
#define BNO055_GYRO_HIGHRATE_Z_THRES_LEN		(5)
#define BNO055_GYRO_HIGHRATE_Z_THRES_REG    BNO055_GYRO_HIGHRATE_Z_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Z_HYST_POS		(5)
#define BNO055_GYRO_HIGHRATE_Z_HYST_MSK		(0X60)
#define BNO055_GYRO_HIGHRATE_Z_HYST_LEN		(2)
#define BNO055_GYRO_HIGHRATE_Z_HYST_REG		BNO055_GYRO_HIGHRATE_Z_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Z_DURN_POS		(0)
#define BNO055_GYRO_HIGHRATE_Z_DURN_MSK		(0XFF)
#define BNO055_GYRO_HIGHRATE_Z_DURN_LEN		(8)
#define BNO055_GYRO_HIGHRATE_Z_DURN_REG		(BNO055_GYRO_DURN_Z_ADDR)

/*Gyro any motion threshold setting*/
#define BNO055_GYRO_ANY_MOTION_THRES_POS		(0)
#define BNO055_GYRO_ANY_MOTION_THRES_MSK		(0X7F)
#define BNO055_GYRO_ANY_MOTION_THRES_LEN		(7)
#define BNO055_GYRO_ANY_MOTION_THRES_REG		\
BNO055_GYRO_ANY_MOTION_THRES_ADDR

/* Gyro any motion slope sample setting*/
#define BNO055_GYRO_SLOPE_SAMPLES_POS		(0)
#define BNO055_GYRO_SLOPE_SAMPLES_MSK		(0X03)
#define BNO055_GYRO_SLOPE_SAMPLES_LEN		(2)
#define BNO055_GYRO_SLOPE_SAMPLES_REG		BNO055_GYRO_ANY_MOTION_SET_ADDR

/* Gyro awake duration setting*/
#define BNO055_GYRO_AWAKE_DURN_POS		(2)
#define BNO055_GYRO_AWAKE_DURN_MSK		(0X0C)
#define BNO055_GYRO_AWAKE_DURN_LEN		(2)
#define BNO055_GYRO_AWAKE_DURN_REG		BNO055_GYRO_ANY_MOTION_SET_ADDR

/* PAGE1 DATA REGISTERS DEFINITION END*/
/*************************************************/

typedef enum __attribute__ ((__packed__)) bno055_power_mode_t{
	BNO055_POWER_MODE_NORMAL_MODE	= 0,
	BNO055_POWER_MODE_LOW_POWER_MODE	= 1,
	BNO055_POWER_MODE_SUSPEND_MODE	= 2
}bno055_power_mode_t;

/* Operation mode settings*/
typedef enum __attribute__ ((__packed__)) bno055_opr_mode_t{
	BNO055_OPERATION_MODE_CONFIG			= (0X00),
	BNO055_OPERATION_MODE_ACCONLY			= (0X01),
	BNO055_OPERATION_MODE_MAGONLY			= (0X02),
	BNO055_OPERATION_MODE_GYRONLY			= (0X03),
	BNO055_OPERATION_MODE_ACCMAG			= (0X04),
	BNO055_OPERATION_MODE_ACCGYRO			= (0X05),
	BNO055_OPERATION_MODE_MAGGYRO			= (0X06),
	BNO055_OPERATION_MODE_AMG				= (0X07),
	BNO055_OPERATION_MODE_IMUPLUS			= (0X08),
	BNO055_OPERATION_MODE_COMPASS			= (0X09),
	BNO055_OPERATION_MODE_M4G				= (0X0A),
	BNO055_OPERATION_MODE_NDOF_FMC_OFF		= (0X0B),
	BNO055_OPERATION_MODE_NDOF				= (0X0C)
}bno055_opr_mode_t;

/* System Status */
typedef enum __attribute__ ((__packed__)) bno055_sys_stat_t{
	BNO055_SYS_STAT_SYSTEM_IDLE								= 0,
	BNO055_SYS_STAT_SYSTEM_ERROR,
	BNO055_SYS_STAT_INITIALIZING_PERIPHERALS,
	BNO055_SYS_STAT_SYSTEM_INITIALIZATION,
	BNO055_SYS_STAT_EXECUTING_SELFTEST,
	BNO055_SYS_STAT_SENSOR_FUSION_ALGORITHM_RUNNING,
	BNO055_SYS_STAT_SYSTEM_RUNNING_WITHOUT_FUSION_ALGORITHM
}bno055_sys_stat_t;

/* System Error */
typedef enum __attribute__ ((__packed__)) bno055_sys_err_t{
	BNO055_SYS_ERR_NO_ERROR									= 0,
	BNO055_SYS_ERR_PERIPHERAL_INITIALIZATION_ERROR,
	BNO055_SYS_ERR_SYSTEM_INITIALIZATION_ERROR,
	BNO055_SYS_ERR_SELF_TEST_RESULT_FAILED,
	BNO055_SYS_ERR_REGISTER_MAP_VALUE_OUT_OF_RANGE,
	BNO055_SYS_ERR_REGISTER_MAP_ADDRESS_OUT_OF_RANGE,
	BNO055_SYS_ERR_REGISTER_MAP_WRITE_ERROR,
	BNO055_SYS_ERR_BNO_LOW_POWER_MODE_NOT_AVAILABLE_FOR_SELECTED_OPERATION_MODE,
	BNO055_SYS_ERR_ACCELEROMETER_POWER_MODE_NOT_AVAILABLE,
	BNO055_SYS_ERR_FUSION_ALGORITHM_CONFIGURATION_ERROR,
	BNO055_SYS_ERR_SENSOR_CONFIGURATION_ERROR,
}bno055_sys_err_t;

/********************************************************/
/**\name	REGISTER DEFINITION				            */
/********************************************************/

typedef struct __attribute__ ((__packed__)) bno055_reg_page0_t
{
	u8    chip_id					;
	u8    accel_rev_id				;
	u8    mag_rev_id				;
	u8    gyro_rev_id				;
	u8    sw_rev_id_lsb				;
	u8    sw_rev_id_msb				;
	u8    bl_rev_id					;
	u8	  page_id					;
	u8    accel_data_x_lsb			;
	u8    accel_data_x_msb			;
	u8    accel_data_y_lsb			;
	u8    accel_data_y_msb			;
	u8    accel_data_z_lsb			;
	u8    accel_data_z_msb			;
	u8    mag_data_x_lsb			;
	u8    mag_data_x_msb			;
	u8    mag_data_y_lsb			;
	u8    mag_data_y_msb			;
	u8    mag_data_z_lsb			;
	u8    mag_data_z_msb			;
	u8    gyro_data_x_lsb			;
	u8    gyro_data_x_msb			;
	u8    gyro_data_y_lsb			;
	u8    gyro_data_y_msb			;
	u8    gyro_data_z_lsb			;
	u8    gyro_data_z_msb			;
	u8    euler_h_lsb				;
	u8    euler_h_msb				;
	u8    euler_r_lsb				;
	u8    euler_r_msb				;
	u8    euler_p_lsb				;
	u8    euler_p_msb				;
	u8    quaternion_data_w_lsb		;
	u8    quaternion_data_w_msb		;
	u8    quaternion_data_x_lsb		;
	u8    quaternion_data_x_msb		;
	u8    quaternion_data_y_lsb		;
	u8    quaternion_data_y_msb		;
	u8    quaternion_data_z_lsb		;
	u8    quaternion_data_z_msb		;
	u8    linear_accel_data_x_lsb	;
	u8    linear_accel_data_x_msb	;
	u8    linear_accel_data_y_lsb	;
	u8    linear_accel_data_y_msb	;
	u8    linear_accel_data_z_lsb	;
	u8    linear_accel_data_z_msb	;
	u8    gravity_data_x_lsb		;
	u8    gravity_data_x_msb		;
	u8    gravity_data_y_lsb		;
	u8    gravity_data_y_msb		;
	u8    gravity_data_z_lsb		;
	u8    gravity_data_z_msb		;
	u8    temp						;
	u8    calib_stat				;
	u8    selftest_result			;
	u8    intr_stat					;
	u8    sys_clk_stat				;
	bno055_sys_stat_t   sys_stat	;
	bno055_sys_err_t    sys_err		;
	u8    unit_sel					;
	//u8    data_select				;
	bno055_opr_mode_t	opr_mode	;
	bno055_power_mode_t pwr_mode	;
	u8    sys_trigger				;
	u8    temp_source				;
	u8    axis_map_config			;
	u8    axis_map_sign				;
	//u8    sic_matrix_0_lsb			;
	//u8    sic_matrix_0_msb			;
	//u8    sic_matrix_1_lsb			;
	//u8    sic_matrix_1_msb			;
	//u8    sic_matrix_2_lsb			;
	//u8    sic_matrix_2_msb			;
	//u8    sic_matrix_3_lsb			;
	//u8    sic_matrix_3_msb			;
	//u8    sic_matrix_4_lsb			;
	//u8    sic_matrix_4_msb			;
	//u8    sic_matrix_5_lsb			;
	//u8    sic_matrix_5_msb			;
	//u8    sic_matrix_6_lsb			;
	//u8    sic_matrix_6_msb			;
	//u8    sic_matrix_7_lsb			;
	//u8    sic_matrix_7_msb			;
	//u8    sic_matrix_8_lsb			;
	//u8    sic_matrix_8_msb			;
	u8    accel_offset_x_lsb		;
	u8    accel_offset_x_msb		;
	u8    accel_offset_y_lsb		;
	u8    accel_offset_y_msb		;
	u8    accel_offset_z_lsb		;
	u8    accel_offset_z_msb		;
	u8    mag_offset_x_lsb			;
	u8    mag_offset_x_msb			;
	u8    mag_offset_y_lsb			;
	u8    mag_offset_y_msb			;
	u8    mag_offset_z_lsb			;
	u8    mag_offset_z_msb			;
	u8    gyro_offset_x_lsb			;
	u8    gyro_offset_x_msb			;
	u8    gyro_offset_y_lsb			;
	u8    gyro_offset_y_msb			;
	u8    gyro_offset_z_lsb			;
	u8    gyro_offset_z_msb			;
	u8    accel_radius_lsb			;
	u8    accel_radius_msb			;
	u8    mag_radius_lsb			;
	u8    mag_radius_msb			;
}bno055_reg_page0_t;

typedef struct __attribute__ ((__packed__)) bno055_reg_page1_t
{
	u8  accel_config;
	u8 	mag_config;
	u8 	gyro_config;
	u8 	gyro_mode_config;
	u8 	accel_sleep_config;
	u8 	gyro_sleep_config;
	//u8 	mag_sleep_config;
	u8 	int_mask;
	u8 	int_en;
	u8 	accel_any_motion_thres;
	u8 	accel_intr_settings;
	u8 	accel_high_g_durn;
	u8 	accel_high_g_thres;
	u8 	accel_no_motion_thres;
	u8 	accel_no_motion_set;
	u8 	gyro_intr_seting;
	u8 	gyro_highrate_x_set;
	u8 	gyro_durn_x;
	u8 	gyro_highrate_y_set;
	u8 	gyro_durn_y;
	u8 	gyro_highrate_z_set;
	u8 	gyro_durn_z;
	u8 	gyro_any_motion_thres;
	u8 	gyro_any_motion_set;
}bno055_reg_page1_t;

#define BNO055_REGISTER_PAGE0_COUNT_BYTES	(BNO055_REGISTER_PAGE0_COUNT_BYTES_0 + BNO055_REGISTER_PAGE0_COUNT_BYTES_1 + BNO055_REGISTER_PAGE0_COUNT_BYTES_2)   //107
#define BNO055_REGISTER_PAGE0_COUNT_BYTES_0	60
#define BNO055_REGISTER_PAGE0_COUNT_BYTES_1	6
#define BNO055_REGISTER_PAGE0_COUNT_BYTES_2	22

#define BNO055_REGISTER_PAGE1_COUNT_BYTES	(BNO055_REGISTER_PAGE1_COUNT_BYTES_0 + BNO055_REGISTER_PAGE1_COUNT_BYTES_1) //24
#define BNO055_REGISTER_PAGE1_COUNT_BYTES_0	6
#define BNO055_REGISTER_PAGE1_COUNT_BYTES_1	17

typedef union bno055_reg_page1_u_t
{
	bno055_reg_page1_t reg;
	u8 reg_array[BNO055_REGISTER_PAGE1_COUNT_BYTES];
}bno055_reg_page1_u_t;

typedef union bno055_reg_page0_u_t
{
	bno055_reg_page0_t reg;
	u8 reg_array[BNO055_REGISTER_PAGE0_COUNT_BYTES];
}bno055_reg_page0_u_t;

#endif