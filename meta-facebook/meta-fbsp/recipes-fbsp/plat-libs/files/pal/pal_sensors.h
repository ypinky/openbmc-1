#ifndef __PAL_SENSORS_H__
#define __PAL_SENSORS_H__

#include <openbmc/obmc_pal_sensors.h>

#define MAX_SENSOR_NUM         (0xFF)
#define MAX_DEVICE_NAME_SIZE   (128)
#define MB_TEMP_DEVICE  "/sys/class/i2c-dev/i2c-%d/device/%d-00%x/hwmon/hwmon*/temp1_input"
#define MB_ADC_VOLTAGE_DEVICE "/sys/devices/platform/iio-hwmon/hwmon/hwmon*/in%d_input"

//PECI CMD INFO
#define PECI_RETRY_TIMES                        (0)
#define PECI_CMD_RD_PKG_CONFIG                  (0xA1)
#define PECI_INDEX_ACCUMULATED_ENERGY_STATUS    (3)
#define PECI_INDEX_THERMAL_MARGIN               (10)
#define PECI_INDEX_DIMM_THERMAL_RW              (14)
#define PECI_INDEX_TEMP_TARGET                  (16)
#define PECI_INDEX_TOTAL_TIME                   (31)
#define PECI_THERMAL_DIMM0_BYTE                 (1)
#define PECI_THERMAL_DIMM1_BYTE                 (2)

//NM DEVICE INFO
#define NM_IPMB_BUS_ID   (5)
#define NM_SLAVE_ADDR    (0x2C)

//CPU INFO
#define PECI_CPU0_ADDR    (0x30)
#define PECI_CPU1_ADDR    (0x31)

//AMD1278 CMD INFO
#define PMBUS_PMON_CONFIG  (0xD4)
#define ADM1278_SLAVE_ADDR (0x22)
#define ADM1278_RSENSE     (0.15)

//INA260 CMD INFO
#define INA260_CURRENT   (0x01)
#define INA260_VOLTAGE   (0x02)
#define INA260_POWER     (0x03)

#define PMBUS_PAGE         (0x00)
#define PMBUS_VOUT_MODE    (0x20)
#define PMBUS_VOUT_COMMAND (0x21)
#define PMBUS_READ_VIN     (0x88)
#define PMBUS_READ_IIN     (0x89)
#define PMBUS_READ_VOUT    (0x8B)
#define PMBUS_READ_IOUT    (0x8C)
#define PMBUS_READ_TEMP1   (0x8D)
#define PMBUS_READ_TEMP2   (0x8E)
#define PMBUS_READ_POUT    (0x96)
#define PMBUS_READ_PIN     (0x97)

//Sensor Table
enum {
  MB_SNR_PCH_TEMP = 0x08,
//NIC
  NIC_MEZZ0_SNR_TEMP = 0x10,
  NIC_MEZZ1_SNR_TEMP = 0x11,

  MB_SNR_FAN0_TACH = 0x2A,
  MB_SNR_FAN1_TACH = 0x2B,

  MB_SNR_CPU0_TJMAX = 0x30,
  MB_SNR_CPU1_TJMAX = 0x31,
  MB_SNR_CPU0_PKG_POWER = 0x32,
  MB_SNR_CPU1_PKG_POWER = 0x33,
  MB_SNR_CPU0_THERM_MARGIN = 0x34,
  MB_SNR_CPU1_THERM_MARGIN = 0x35,

//HSC
  MB_SNR_HSC_VIN = 0x40,
  MB_SNR_HSC_IOUT = 0x41,
  MB_SNR_HSC_PIN = 0x42,
  MB_SNR_HSC_TEMP = 0x43,
//DIMM TEMP
  MB_SNR_CPU0_DIMM_GRPA_TEMP = 0x50,
  MB_SNR_CPU0_DIMM_GRPB_TEMP = 0x51,
  MB_SNR_CPU0_DIMM_GRPC_TEMP = 0x52,
  MB_SNR_CPU0_DIMM_GRPD_TEMP = 0x53,
  MB_SNR_CPU0_DIMM_GRPE_TEMP = 0x54,
  MB_SNR_CPU0_DIMM_GRPF_TEMP = 0x55,
  MB_SNR_CPU1_DIMM_GRPA_TEMP = 0x56,
  MB_SNR_CPU1_DIMM_GRPB_TEMP = 0x57,
  MB_SNR_CPU1_DIMM_GRPC_TEMP = 0x58,
  MB_SNR_CPU1_DIMM_GRPD_TEMP = 0x59,
  MB_SNR_CPU1_DIMM_GRPE_TEMP = 0x5A,
  MB_SNR_CPU1_DIMM_GRPF_TEMP = 0x5B,

//HARD DISK TEMP
  MB_SNR_BOOT_DRIVER_TEMP = 0x70,
  MB_SNR_DATA0_DRIVER_TEMP = 0x71,
  MB_SNR_DATA1_DRIVER_TEMP = 0x72,

  MB_SNR_C2_NVME_CTEMP = 0x7B,
  MB_SNR_C3_NVME_CTEMP = 0x7C,
  MB_SNR_C4_NVME_CTEMP = 0x7D,

  MB_SNR_C4_AVA_FTEMP = 0x7E,
  MB_SNR_C4_AVA_RTEMP = 0x7F,

  MB_SNR_C2_AVA_FTEMP = 0x80,
  MB_SNR_C2_AVA_RTEMP = 0x81,
  MB_SNR_C2_1_NVME_CTEMP = 0x82,
  MB_SNR_C2_2_NVME_CTEMP = 0x83,
  MB_SNR_C2_3_NVME_CTEMP = 0x84,
  MB_SNR_C2_4_NVME_CTEMP = 0x85,
  MB_SNR_C3_AVA_FTEMP = 0x86,
  MB_SNR_C3_AVA_RTEMP = 0x87,
  MB_SNR_C3_1_NVME_CTEMP = 0x88,
  MB_SNR_C3_2_NVME_CTEMP = 0x89,
  MB_SNR_C3_3_NVME_CTEMP = 0x8A,
  MB_SNR_C3_4_NVME_CTEMP = 0x8B,
  MB_SNR_C4_1_NVME_CTEMP = 0x8C,
  MB_SNR_C4_2_NVME_CTEMP = 0x8D,
  MB_SNR_C4_3_NVME_CTEMP = 0x8E,
  MB_SNR_C4_4_NVME_CTEMP = 0x8F,
//INA260
  MB_SNR_P3V3_STBY_INA260_VOL = 0x90,
  MB_SNR_P3V3_M2_1_INA260_VOL = 0x91,
  MB_SNR_P3V3_M2_2_INA260_VOL = 0x92,
  MB_SNR_P3V3_M2_3_INA260_VOL = 0x93,

  MB_SNR_POWER_FAIL = 0x9C,
  MB_SNR_MEMORY_LOOP_FAIL = 0x9D,
//Board TEMP  
  MB_SNR_INLET_TEMP = 0xA0,
  MB_SNR_OUTLET_TEMP_R = 0xA1,
  MB_SNR_OUTLET_TEMP_L = 0xA2,
  MB_SNR_INLET_REMOTE_TEMP = 0xA3,
  MB_SNR_OUTLET_REMOTE_TEMP = 0xA4,
//CPU TEMP  
  MB_SNR_CPU0_TEMP = 0xAA,
  MB_SNR_CPU1_TEMP = 0xAB,
//CPU VR
  MB_SNR_VR_CPU0_VCCIN_VOLT = 0xB0,
  MB_SNR_VR_CPU0_VCCIN_TEMP = 0xB1,
  MB_SNR_VR_CPU0_VCCIN_CURR = 0xB2,
  MB_SNR_VR_CPU0_VCCIN_POWER = 0xB3,
  MB_SNR_VR_CPU0_VSA_VOLT = 0xB4,
  MB_SNR_VR_CPU0_VSA_TEMP = 0xB5,
  MB_SNR_VR_CPU0_VSA_CURR = 0xB6,
  MB_SNR_VR_CPU0_VSA_POWER = 0xB7,
  MB_SNR_VR_CPU0_VCCIO_VOLT = 0xB8,
  MB_SNR_VR_CPU0_VCCIO_TEMP = 0xB9,
  MB_SNR_VR_CPU0_VCCIO_CURR = 0xBA,
  MB_SNR_VR_CPU0_VCCIO_POWER = 0xBB,
  MB_SNR_VR_CPU0_VDDQ_GRPABC_VOLT = 0xBC,
  MB_SNR_VR_CPU0_VDDQ_GRPABC_TEMP = 0xBD,
  MB_SNR_VR_CPU0_VDDQ_GRPABC_CURR = 0xBE,
  MB_SNR_VR_CPU0_VDDQ_GRPABC_POWER = 0xBF,
  MB_SNR_VR_CPU0_VDDQ_GRPDEF_VOLT = 0xC0,
  MB_SNR_VR_CPU0_VDDQ_GRPDEF_TEMP = 0xC1,
  MB_SNR_VR_CPU0_VDDQ_GRPDEF_CURR = 0xC2,
  MB_SNR_VR_CPU0_VDDQ_GRPDEF_POWER = 0xC3,
//PCH VR
  MB_SNR_VR_PCH_P1V05_VOLT = 0xC4,
  MB_SNR_VR_PCH_P1V05_TEMP = 0xC5,
  MB_SNR_VR_PCH_P1V05_CURR = 0xC6,
  MB_SNR_VR_PCH_P1V05_POWER = 0xC7,
  MB_SNR_VR_PCH_PVNN_VOLT = 0xC8,
  MB_SNR_VR_PCH_PVNN_TEMP = 0xC9,
  MB_SNR_VR_PCH_PVNN_CURR = 0xCA,
  MB_SNR_VR_PCH_PVNN_POWER = 0xCB, 
//ADC
  MB_SNR_P5V = 0xD0,  
  MB_SNR_P5V_STBY = 0xD1,
  MB_SNR_P3V3_STBY = 0xD2,
  MB_SNR_P3V3 = 0xD3,
  MB_SNR_P3V_BAT = 0xD4,
  MB_SNR_CPU_1V8 = 0xD5,
  MB_SNR_PCH_1V8 = 0xD6,
  MB_SNR_CPU0_PVPP_ABC= 0xD7,
  MB_SNR_CPU1_PVPP_ABC= 0xD8,
  MB_SNR_CPU0_PVPP_DEF= 0xD9,
  MB_SNR_CPU1_PVPP_DEF= 0xDA,
  MB_SNR_CPU0_PVTT_ABC= 0xDB,
  MB_SNR_CPU1_PVTT_ABC= 0xDC,
  MB_SNR_CPU0_PVTT_DEF= 0xDD,
  MB_SNR_CPU1_PVTT_DEF= 0xDE,
  MB_SNR_PROCESSOR_FAIL = 0xDF,
//VR CPU1
  MB_SNR_VR_CPU1_VCCIN_VOLT = 0xE0,
  MB_SNR_VR_CPU1_VCCIN_TEMP = 0xE1,
  MB_SNR_VR_CPU1_VCCIN_CURR = 0xE2,
  MB_SNR_VR_CPU1_VCCIN_POWER = 0xE3,
  MB_SNR_VR_CPU1_VSA_VOLT = 0xE4,
  MB_SNR_VR_CPU1_VSA_TEMP = 0xE5,
  MB_SNR_VR_CPU1_VSA_CURR = 0xE6,
  MB_SNR_VR_CPU1_VSA_POWER = 0xE7,
  MB_SNR_VR_CPU1_VCCIO_VOLT = 0xE8,
  MB_SNR_VR_CPU1_VCCIO_TEMP = 0xE9,
  MB_SNR_VR_CPU1_VCCIO_CURR = 0xEA,
  MB_SNR_VR_CPU1_VCCIO_POWER = 0xEB,
  MB_SNR_VR_CPU1_VDDQ_GRPABC_VOLT = 0xEC,
  MB_SNR_VR_CPU1_VDDQ_GRPABC_TEMP = 0xED,
  MB_SNR_VR_CPU1_VDDQ_GRPABC_CURR = 0xEE,
  MB_SNR_VR_CPU1_VDDQ_GRPABC_POWER = 0xEF,
  MB_SNR_VR_CPU1_VDDQ_GRPDEF_VOLT = 0xF0,
  MB_SNR_VR_CPU1_VDDQ_GRPDEF_TEMP = 0xF1,
  MB_SNR_VR_CPU1_VDDQ_GRPDEF_CURR = 0XF2,
  MB_SNR_VR_CPU1_VDDQ_GRPDEF_POWER = 0XF3,
};

typedef struct {
  float ucr_thresh;
  float unc_thresh;
  float unr_thresh;
  float lcr_thresh;
  float lnc_thresh;
  float lnr_thresh;
  float pos_hyst;
  float neg_hyst;
} PAL_SENSOR_THRESHOLD;

enum {
  TEMP = 1,
  CURR,
  VOLT,
  FAN,
  POWER,
};

typedef struct {
  char* snr_name;
  uint8_t id;
  int (*read_sensor) (uint8_t id, float *value);
  uint8_t stby_read;
  PAL_SENSOR_THRESHOLD snr_thresh;
  uint8_t units;
} PAL_SENSOR_MAP;

//ADC INFO
enum {
  ADC0 = 0,
  ADC1,
  ADC2,
  ADC3,
  ADC4,
  ADC5,
  ADC6,
  ADC7,
  ADC8,
  ADC9,
  ADC10,
  ADC11, 
  ADC12, 
  ADC13, 
  ADC14,
};

//INA260 INFO
enum {
  INA260_ID0,
  INA260_ID1,
  INA260_ID2,
  INA260_ID3,
};

//GENERIC I2C Sensors
enum {
  TEMP_INLET = 0,
  TEMP_OUTLET_L,
  TEMP_OUTLET_R,
};

//NIC INFO
enum {
  MEZZ0 = 0,
  MEZZ1,
};

//HARD DISK INFO
enum {
  DISK_BOOT = 0,
  DISK_DATA0,
  DISK_DATA1,
};

//PECI CPU INFO
enum {
  CPU_ID0 = 0,
  CPU_ID1 = 1,
};

typedef struct {
  uint8_t cpu_id;
  uint8_t cpu_addr;
}PAL_CPU_INFO;

enum {
  DIMM_CRPA = 0,
  DIMM_CRPB = 1,
  DIMM_CRPC = 2,
  DIMM_CRPD = 3,
  DIMM_CRPE = 4,
  DIMM_CRPF = 5,
};

typedef struct {
  uint8_t cpu_addr;
  uint8_t index;
  uint8_t dev_info;
  uint8_t para_l;
  uint8_t para_h;
} PECI_RD_PKG_CONFIG_INFO;

//ADM1278 INFO
enum {
  ADM1278_VOLTAGE = 0,
  ADM1278_CURRENT,
  ADM1278_POWER,
  ADM1278_TEMP,
};

typedef struct {
  uint8_t type;
  float m;
  float b;
  float r;
} PAL_ADM1278_INFO;

//HSC INFO
enum {
  HSC_ID0,
};

typedef struct {
  uint8_t id;
  uint8_t slv_addr;
  PAL_ADM1278_INFO* info;
} PAL_HSC_INFO;

//NM ID
enum {
  NM_ID0,
};

//PCH SENSOR INFO
enum {
  NM_PCH_TEMP = 8,
};

typedef struct {
  uint8_t id;
  uint8_t bus;
  uint8_t slv_addr;
} PAL_I2C_BUS_INFO;

typedef struct {
  int integer :10;
  uint8_t fract :6;
} PAL_S10_6_FORMAT;

//VR TPS53688 INFO
enum {
  VR_ID0 = 0,
  VR_ID1,
  VR_ID2,
  VR_ID3,
  VR_ID4,
  VR_ID5,
  VR_ID6,
  VR_ID7,
  VR_ID8,
  VR_ID9,
};

#endif
