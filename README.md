# ATM Banking System

A modular C++ console application simulating an ATM (Automated Teller Machine) interface with essential banking operations including quick withdraw, normal withdraw, deposit, and balance checking functionalities.

## Overview

This ATM Banking System represents a client-side banking application built using **Functional Programming** principles with a clean modular architecture. Unlike administrative banking systems, this project focuses on the customer experience, providing a simplified ATM-like interface for individual account operations.

### Programming Paradigm

This version uses **Functional Programming** approach with modular design:
- **Function-based architecture** organized across 7 specialized modules
- **Session-based client context** maintaining current user state  
- **Transaction-focused design** optimized for customer interactions
- **Input validation functions** ensuring secure operations
- **File-based persistence** for account data synchronization

### Future Development

An **Object-Oriented Programming (OOP)** version is planned featuring:
- **ATM class hierarchy** (ATM, Transaction, Account classes)
- **State pattern implementation** for ATM operational states
- **Strategy pattern** for different withdrawal methods
- **Observer pattern** for transaction monitoring
- **Enhanced security through encapsulation**

## Project Architecture

### Modular File Structure
```
ATM-System/
├── headers/            → Header files (.h)
│   ├── Client.h        → Data structures and enums
│   ├── Utils.h         → Utility functions
│   ├── FileManager.h   → File I/O operations
│   ├── Authentication.h  → Login and validation
│   ├── ATMOperations.h  → Transaction processing
│   └── UserInterface.h  → Menu systems
├── src/                → Source files (.cpp)
│   ├── Globals.cpp     → Global variables
│   ├── Utils.cpp       → Utility implementations
│   ├── FileManager.cpp  → File operations
│   ├── Authentication.cpp  → Login logic
│   ├── ATMOperations.cpp  → Transaction logic
│   └── UserInterface.cpp  → UI implementations
├── data/
│   └── Clients.txt     → Client account database
├── main.cpp            → Application entry point
└── build.bat           → Build automation script
```

### Module Breakdown

**Authentication Module**: Handles secure client login with account number and PIN validation
**File Manager Module**: Manages persistent data storage and retrieval operations
**ATM Operations Module**: Processes all banking transactions (withdraw, deposit, balance)
**User Interface Module**: Manages console-based menus and user interactions
**Utils Module**: Provides shared utility functions for string processing
**Client Module**: Defines core data structures and system enumerations

## What's New in This Version

This ATM system represents a completely different perspective on banking software - the customer interface:

> Want to see the administrative versions?
> - [Basic Bank Management](https://github.com/AbdelhamidSherif/bank-management-functional-cpp) - Admin CRUD operations
> - [Enhanced Bank System](https://github.com/AbdelhamidSherif/enhanced-bank-system-functional) - Admin with transactions  
> - [Secure Bank System](https://github.com/AbdelhamidSherif/secure-bank-system-functional) - Multi-user admin system

### Key Differences from Admin Systems

| Feature | Admin Systems | ATM System (Current) |
|---------|---------------|---------------------|
| **Target User** | Bank Employees | Bank Customers |
| **Authentication** | Username/Password | Account Number/PIN |
| **Operations** | Full CRUD + User Management | Self-service banking only |
| **Access Level** | Multiple accounts management | Single account operations |
| **Interface** | Administrative menus | ATM-style interface |
| **Workflow** | Complex multi-step operations | Quick, simple transactions |

## Core Features

### Customer Authentication
- **Account Number/PIN Login**: Simple two-factor authentication
- **Session Management**: Current client context throughout session
- **Invalid Login Protection**: Continuous retry until successful login
- **Automatic Logout**: Session ends when user chooses to exit

### ATM Operations

#### Quick Withdraw
- **Predefined Amounts**: 8 preset withdrawal options (20, 50, 100, 200, 400, 600, 800, 1000)
- **Balance Validation**: Automatic checking against available funds
- **Instant Processing**: Single-click withdrawal for common amounts

#### Normal Withdraw  
- **Custom Amounts**: User-defined withdrawal amounts
- **Denomination Validation**: Enforces multiples of 5 (realistic ATM constraint)
- **Balance Protection**: Prevents overdraft attempts
- **Confirmation Required**: Transaction confirmation before processing

#### Deposit Operations
- **Positive Amount Validation**: Ensures only valid deposit amounts
- **Real-time Balance Update**: Immediate reflection of new balance
- **Transaction Confirmation**: User confirmation before finalizing deposit

#### Balance Inquiry
- **Current Balance Display**: Real-time account balance viewing
- **No Transaction Fees**: Free balance checking (as per real ATMs)

## Technical Architecture

### Modular Design Benefits
- **Maintainable Code**: Each module handles specific functionality
- **Reusable Components**: Modules can be used in other projects
- **Team Collaboration**: Multiple developers can work on different modules
- **Easy Testing**: Individual modules can be tested separately
- **Clear Separation**: Business logic separated from UI and data layers

### Data Structure
```cpp
struct sClient {
    string AccountNumber;    // Unique account identifier
    string PinCode;         // 4-digit PIN for authentication  
    string Name;            // Account holder name
    string Phone;           // Contact information
    double AccountBalance;   // Current account balance
    bool MarkForDelete;     // Deletion flag (unused in ATM)
};
```

### Core Module Functions

#### Authentication Module (`Authentication.cpp`)
- `LoadClientInfo()` - Validates account number and PIN combination
- `FinedClientByAccountNumberAndPinCode()` - Searches client database
- `Login()` - Handles authentication flow with retry mechanism

#### File Manager Module (`FileManager.cpp`)
- `LoadClientsDataFromFile()` - Reads client data from storage
- `SaveCleintsDataToFile()` - Persists transaction data to file
- `ConvertLineToRecord()` - Parses file data to client structure
- `ConvertRecordToLine()` - Serializes client data for storage

#### ATM Operations Module (`ATMOperations.cpp`)
- `GetQuickWithDrawAmount()` - Maps quick withdraw options to amounts
- `DepositBalanceToClientByAccountNumber()` - Processes all balance changes
- `ReadWithDrawAmont()` - Validates custom withdrawal amounts (multiples of 5)
- `ReadDepositAmount()` - Validates positive deposit amounts

#### User Interface Module (`UserInterface.cpp`)
- `ShowMainMenue()` - Main ATM menu interface
- `ShowQuickWithdrawScreen()` - Interactive quick withdrawal interface
- `ShowNormalWithDrawScreen()` - Custom withdrawal interface  
- `ShowDepositScreen()` - Deposit operation interface
- `ShowCheckBalanceScreen()` - Balance display interface

## Getting Started

### Prerequisites
- C++ compiler (GCC, MSVC, or Clang)
- Standard C++ libraries
- Windows OS (due to `system("cls")` and `system("pause>0")` commands)

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/AbdelhamidSherif/atm-banking-system-cpp.git
   cd atm-banking-system-cpp
   ```

2. **Compile the program**
   ```bash
   g++ -o atm_system main.cpp
   ```

3. **Setup client data**
   Create `Clients.txt` with sample account data:
   ```
   A001#//#1234#//#John Smith#//#01234567890#//#5000.000000
   A002#//#5678#//#Jane Doe#//#01234567891#//#3200.000000
   ```

4. **Run the application**
   ```bash
   ./atm_system
   ```

## Usage

### Login Process
```
---------------------------------
    Login Screen
---------------------------------
Enter Account Number? A001
Enter Pin? 1001
```

### Sample Test Accounts
The system comes with pre-loaded test accounts in `data/Clients.txt`:

**Small Balance Accounts** (for testing overdraft protection):
- Account: `A007` | PIN: `1007` | Balance: $125.00
- Account: `A010` | PIN: `1010` | Balance: $580.00

**Medium Balance Accounts** (for normal testing):
- Account: `A001` | PIN: `1001` | Balance: $1,500.00
- Account: `A004` | PIN: `1004` | Balance: $950.00

**High Balance Accounts** (for large transactions):
- Account: `A002` | PIN: `1002` | Balance: $2,500.00
- Account: `A008` | PIN: `1008` | Balance: $3,200.00

### ATM Main Menu
```
===========================================
        ATM Main Menu Screen
===========================================
    [1] Quick Withdraw.
    [2] Normal Withdraw.
    [3] Deposit
    [4] Check Balance.
    [5] Logout.
===========================================
```

### Quick Withdraw Interface
```
===========================================
        Quick Withdraw
===========================================
    [1] 20        [2] 50
    [3] 100       [4] 200
    [5] 400       [6] 600
    [7] 800       [8] 1000
    [9] Exit
===========================================
Your Balance is 5000
```

### Sample Transaction Flow

#### Making a Quick Withdrawal:
```
Choose what to do from [1] to [9] ? 3
Are you sure you want perform this transaction? y/n ? y
Done Successfully. New balance is: 4900
```

#### Making a Custom Withdrawal:
```
Enter an amount multiple of 5's ? 175
Are you sure you want perform this transaction? y/n ? y
Done Successfully. New balance is: 4725
```

#### Making a Deposit:
```
Enter a positive Deposit Amount? 500
Are you sure you want perform this transaction? y/n ? y
Done Successfully. New balance is: 5225
```

## File Structure

```
ATM-System/
├── headers/
│   ├── Client.h           # Data structures and enumerations
│   ├── Utils.h            # Utility function declarations
│   ├── FileManager.h      # File I/O operation declarations
│   ├── Authentication.h   # Login system declarations
│   ├── ATMOperations.h    # Transaction processing declarations
│   └── UserInterface.h    # Menu system declarations
├── src/
│   ├── Globals.cpp        # Global variable definitions
│   ├── Utils.cpp          # String processing utilities
│   ├── FileManager.cpp    # File operations implementation
│   ├── Authentication.cpp # Login and validation logic
│   ├── ATMOperations.cpp  # Transaction processing logic
│   └── UserInterface.cpp  # Menu and UI implementations
├── data/
│   └── Clients.txt        # Client account database
├── main.cpp               # Application entry point
├── build.bat              # Automated build script
└── README.md              # This documentation
```

## Security Features

### Authentication Security
- **PIN-based access** with account number verification
- **Session isolation** - each login creates isolated session
- **No account enumeration** - system doesn't reveal valid account numbers

### Transaction Security  
- **Balance validation** prevents overdraft attempts
- **Amount validation** enforces realistic constraints
- **Confirmation prompts** for all financial operations
- **Real-time balance updates** maintain data consistency

### Data Protection
- **File-based persistence** with structured data format
- **Session-based operations** no permanent credential storage
- **Input sanitization** throughout the application

## Code Statistics

- **Total Files**: 13 files organized in 4 directories
- **Header Files**: 6 modular interface definitions
- **Source Files**: 6 implementation modules + main.cpp
- **Total Lines**: ~400 lines across all modules
- **Functions**: 25+ specialized ATM functions
- **Focus**: Customer-facing operations with modular architecture
- **Complexity**: Simplified interface with clean separation of concerns

## Future Enhancements

### ATM Features
- [ ] Receipt generation and printing simulation
- [ ] Multiple account support per customer
- [ ] Mini-statement functionality
- [ ] PIN change capability
- [ ] Account transfer between accounts
- [ ] Bill payment simulation

### Security Improvements  
- [ ] PIN encryption/hashing
- [ ] Maximum attempt lockout
- [ ] Session timeout implementation
- [ ] Transaction limits (daily/monthly)
- [ ] Audit trail logging

### Technical Upgrades
- [ ] GUI interface with modern framework
- [ ] Database integration instead of file-based storage
- [ ] Network connectivity for real-time banking
- [ ] Multi-language support
- [ ] Accessibility features compliance

## Related Projects

This ATM system completes the banking software ecosystem from both administrative and customer perspectives:

### Project Family
1. **[Basic Bank Management](https://github.com/AbdelhamidSherif/bank-management-functional-cpp)** - Administrative CRUD operations
2. **[Enhanced Bank System](https://github.com/AbdelhamidSherif/enhanced-bank-system-functional)** - Administrative with transactions
3. **[Secure Bank System](https://github.com/AbdelhamidSherif/secure-bank-system-functional)** - Multi-user administrative system
4. **Current Project** - Customer-facing ATM interface
5. **Coming Soon** - Object-Oriented versions of all systems

### Quick Navigation
- [View Basic Admin System →](https://github.com/AbdelhamidSherif/bank-management-functional-cpp) - Learn administrative operations
- [View Enhanced Admin System →](https://github.com/AbdelhamidSherif/enhanced-bank-system-functional) - See transaction management
- [View Secure Admin System →](https://github.com/AbdelhamidSherif/secure-bank-system-functional) - Understand user authentication
- [See All Banking Projects →](https://github.com/AbdelhamidSherif?tab=repositories&q=bank&type=&language=) - Complete ecosystem

## Contributing

Contributions are welcome! This project demonstrates customer-focused functional programming design.

### Contribution Areas
- ATM user experience improvements
- Additional transaction types
- Security enhancements
- Performance optimizations
- Documentation improvements

### Steps to Contribute
1. Fork the repository
2. Create your feature branch (`git checkout -b feature/ReceiptGeneration`)
3. Commit your changes (`git commit -m 'Add receipt printing simulation'`)
4. Push to the branch (`git push origin feature/ReceiptGeneration`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Abdelhamid Sherif**
- GitHub: [@AbdelhamidSherif](https://github.com/AbdelhamidSherif)
- LinkedIn: [Abdelhamid Sherif](https://linkedin.com/in/abdelhamid-sherif)

## Support

For questions or support:
1. Check existing issues in the repository
2. Create a new issue with detailed description
3. Contact the maintainer directly

## Acknowledgments

- Inspired by real-world ATM interfaces and user experience design
- Educational project demonstrating customer-focused functional programming
- Part of comprehensive banking system series covering both administrative and customer perspectives

---

If you found this project helpful, please give it a star on GitHub!
