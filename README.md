# 🔍 Lost & Found Management System

> A lightweight, file-persistent C application for managing lost and found items — built for simplicity, clarity, and real-world use.

---

## 📌 Overview

The **Lost & Found Management System** is a console-based C program that allows users to log, track, and view lost and found items. All entries are automatically saved to local text files, ensuring data persists between sessions.

Whether you're managing a school, office, or community center — this system gives you a simple, no-dependency solution to keep track of missing and recovered items.

---

## ✨ Features

| Feature              | Description                                          |
|----------------------|------------------------------------------------------|
| ➕ Add Lost Item      | Log an item with name, date, location, and contact   |
| ➕ Add Found Item     | Record a found item with full details                |
| 📋 View Lost Items   | Display all currently logged lost items              |
| 📋 View Found Items  | Display all currently logged found items             |
| 💾 File Persistence  | Data auto-saved to `lost.txt` and `found.txt`        |
| 🚪 Clean Exit        | Gracefully exit with a credits message               |

---

## 🗂️ Project Structure

```
lost-and-found/
│
├── main.c          # Main source file (all logic)
├── lost.txt        # Auto-generated: stores lost item records
├── found.txt       # Auto-generated: stores found item records
└── README.md       # Project documentation
```

---

## 🚀 Getting Started

### Prerequisites

- A C compiler (e.g., **GCC**, **MinGW**, **Clang**)
- Terminal / Command Prompt

### Compilation

```bash
gcc main.c -o lost_and_found
```

### Run

```bash
./lost_and_found        # Linux / macOS
lost_and_found.exe      # Windows
```

---

## 🖥️ Usage

Once launched, you'll see the main menu:

```
====================================
   LOST & FOUND MANAGEMENT SYSTEM
====================================
1. Add Lost Item
2. Add Found Item
3. View Lost Items
4. View Found Items
5. Exit
------------------------------------
Enter choice:
```

Each item entry collects:
- **Item Name** — what was lost or found
- **Date** — in `dd/mm/yyyy` format
- **Place** — location where it was lost or found
- **Contact** — phone number or name to reach

---

## 💾 Data Storage

Records are stored in plain text files in the following format:

```
ItemName | Date | Place | Contact
```

**Example (`lost.txt`):**
```
Blue Backpack | 12/04/2025 | Library Block B | 0300-1234567
AirPods Case | 15/04/2025 | Cafeteria | 0321-9876543
```

> Files are created automatically on first use. No setup required.

---

## 🧱 Data Structures

```c
struct Item {
    char name[50];     // Name of the item
    char date[20];     // Date lost/found
    char place[50];    // Location lost/found
    char contact[30];  // Contact information
};
```

- `lost[100]`  — in-memory array for lost items (max 100)
- `found[100]` — in-memory array for found items (max 100)

---

## ⚠️ Limitations

- Maximum **100 items** per category (in-memory)
- No **search or filter** functionality (yet)
- No **delete or edit** capability
- Data is **session-loaded from file** only at compile-time arrays — items added in previous sessions are saved to file but not reloaded into memory on restart

---

## 🔮 Possible Improvements

- [ ] Load existing records from file on startup
- [ ] Search items by name or location
- [ ] Delete or mark items as resolved/matched
- [ ] Match lost and found items automatically
- [ ] Add timestamps using `<time.h>`
- [ ] Cap input to prevent buffer overflow

---

## 👨‍💻 Author

**Danish Raheem**  
_Built with C — simple, efficient, and to the point._

> *"How did you find my secret..?? anyway hi!"* 🙂

---

## 📄 License

This project is open for personal and educational use. Feel free to modify and build upon it.
