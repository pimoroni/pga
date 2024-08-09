// Board and hardware specific configuration
#define MICROPY_HW_BOARD_NAME                   "PGA2040"

// Portion of onboard flash to reserve for the user filesystem
// PGA2040 has 8MB flash, so reserve 1MiB for the firmware and leave 7MiB
#define MICROPY_HW_FLASH_STORAGE_BYTES          (7 * 1024 * 1024)
