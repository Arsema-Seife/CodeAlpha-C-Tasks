# 🔐 Simple Login & Registration System (C++)

This is a beginner-friendly C++ console program that lets users **register and log in** using a username and password. User data is stored in individual `.txt` files — super simple and perfect for learning! 📚✨

## 🔹 Features
- Register new users ✅  
- Login with saved credentials 🔑  
- Each user gets their own `<username>.txt` file  
- Converts usernames to lowercase (no case-sensitivity issues)  
- Input validation for menu & login attempts  
- Runs in a loop until the user exits 🔁  

## 🔹 How It Works
- When a user registers, the program creates a file containing:
  - username
  - password
- During login, it reads the file and checks if credentials match  
- If the file doesn't exist → **User not found**  
- Incorrect password → **Invalid credentials**  

## 🔹 Notes
- Made for learning basics of **file handling, functions, and strings** in C++ 💻  
- Not for real security — passwords are stored as plain text 😅  
- Great mini-project for university beginners! 🎓✨  


