Each folder in the root directory represents a self-contained project.

```
.
├── 001 hello/                  # Basic LED blink (startup project)
├── 002 sizeoff/                # Memory size exploration
├── 003add/                     # Addition using registers
├── GPIO_input/                 # Button input handling
├── GPIO_output/                # Manual GPIO control
├── led/                        # Basic LED ON/OFF control
├── led_button/                 # Button-controlled LED
├── led_improved/               # Improved button debounce logic
├── led_toggle/                # Toggling LED using button press
├── systick/                    # Using SysTick timer for delays
├── uart_tx/                    # UART transmit
├── uart_rx/                    # UART receive
├── uart_print_tx/              # UART printf style transmission
├── uart_modualr/              # Modular UART code structure
└── ...
```

## 🔧 Tools & Technologies

- **MCU**: STM32F756ZG (Cortex-M7)
- **IDE**: STM32CubeIDE
- **Language**: C (Bare-Metal)
- **Build System**: STM32Cube-generated Makefiles
- **Debug**: ST-Link, Serial Monitor

## 📚 Key Concepts Covered

- ✅ GPIO Input/Output
- ✅ Interrupts & NVIC
- ✅ SysTick Timer
- ✅ UART (Transmit/Receive)
- ✅ Memory-mapped registers
- ✅ Linker Scripts & Startup Files
- ✅ Modular code organization
- ✅ Bare-metal debugging

## 🗃️ Folder Contents

Each project folder includes:
- `Src/` – Application logic (`main.c`, `syscalls.c`, etc.)
- `Inc/` – Headers
- `Startup/` – Assembly startup files
- `*.ld` – Linker script
- `.ioc` – STM32CubeMX project file (optional)

## 🛠️ How to Use

1. Clone this repository:
   ```bash
   git clone https://github.com/Likith025/stm_bare_metal.git
   ```
2. Open the project in **STM32CubeIDE**.
3. Import the desired folder as an existing project.
4. Build & flash to your **STM32F756 Nucleo board**.

## 🙋‍♂️ Author

**Likith R**  
📍 Embedded Firmware Developer  
🔗 [LinkedIn](https://www.linkedin.com/in/likith-r-5a8857228)

## ⭐️ Support

If you find this repository helpful, feel free to give it a ⭐️ and share it with others!

## 📝 License

This repository is open-source and available under the [MIT License](LICENSE).
