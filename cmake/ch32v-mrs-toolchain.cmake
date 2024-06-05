# SPDX-FileCopyrightText: 2023 Rafael G. Martins <rafael@rafaelmartins.eng.br>
# SPDX-License-Identifier: BSD-3-Clause

set(CMAKE_SYSTEM_NAME      Generic-ELF)
set(CMAKE_SYSTEM_PROCESSOR riscv-none-embed)

set(CMAKE_ASM_COMPILER   "${MRS_TOOLCHAIN_PATH}/RISC-V Embedded GCC/bin/riscv-none-embed-gcc.exe")
set(CMAKE_C_COMPILER     "${MRS_TOOLCHAIN_PATH}/RISC-V Embedded GCC/bin/riscv-none-embed-gcc.exe")
set(CMAKE_CXX_COMPILER   "${MRS_TOOLCHAIN_PATH}/RISC-V Embedded GCC/bin/riscv-none-embed-g++.exe")
set(RISCV_SIZE           "${MRS_TOOLCHAIN_PATH}/RISC-V Embedded GCC/bin/riscv-none-embed-size.exe")
set(RISCV_OBJCOPY        "${MRS_TOOLCHAIN_PATH}/RISC-V Embedded GCC/bin/riscv-none-embed-objcopy.exe")
set(RISCV_OBJDUMP        "${MRS_TOOLCHAIN_PATH}/RISC-V Embedded GCC/bin/riscv-none-embed-objdump.exe")
set(RISCV_OPENOCD        "${MRS_TOOLCHAIN_PATH}/OpenOCD/bin/openocd.exe")
set(RISCV_OPENOCD_CONFIG "${MRS_TOOLCHAIN_PATH}/OpenOCD/bin/wch-riscv.cfg")

# as the elf is not stored verbatim into the microncontroller's flash, we can always have debug symbols included
set(CMAKE_ASM_FLAGS_INIT        "-ggdb3 -msmall-data-limit=8 -mno-save-restore -ffunction-sections -fdata-sections")
set(CMAKE_C_FLAGS_INIT          "-ggdb3 -msmall-data-limit=8 -mno-save-restore -ffunction-sections -fdata-sections")
set(CMAKE_CXX_FLAGS_INIT        "-ggdb3 -msmall-data-limit=8 -mno-save-restore -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-ggdb3 -msmall-data-limit=8 -mno-save-restore -ffunction-sections -fdata-sections -nostartfiles -Xlinker --gc-sections --specs=nano.specs --specs=nosys.specs")

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
