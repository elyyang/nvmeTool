#include <stdio.h>
#include <stdint.h>

// 1. Define the hardware interface (HAL)
typedef uint32_t (*sensor_read_fn)(void);

// 2. Real hardware function (would talk to actual memory-mapped registers)
uint32_t real_sensor_read(void) 
{
    // Fictional hardware register access: *(volatile uint32_t*)0x40021000
    return 42; 
}

// 3. Mock hardware function for unit testing
uint32_t mock_sensor_read(void) 
{
    // mock value for testing
    uint32_t mock_sensor_read_value = 100;
    return mock_sensor_read_value;
}

// 4. Firmware business logic depending on the sensor
int process_sensor_data(sensor_read_fn read_sensor) 
{
    uint32_t val = read_sensor();
    if (val > 50) {
        return 1; // High state alert
    }
    return 0; // Normal state
}

// 5. Running a test with the mock
int test_main(void) 
{
    // Injecting the mock function instead of real_sensor_read
    int result = process_sensor_data(mock_sensor_read);
    printf("Processed result using mock data: %d\n", result);
    return 0;
}
