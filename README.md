Here's a modified version for a **get_next_line** project:

# **get_next_line** 📖  
**Read a file line by line in C**  

![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)  
![GitHub last commit](https://img.shields.io/github/last-commit/flotschilein/get_next_line)  

---

## **📖 Description**  
**get_next_line** is a 42 School project that reads a file descriptor line by line. It's a useful function for file processing and can handle multiple file descriptors simultaneously.

Key features:
- Works with any file descriptor
- Uses static variables to maintain state between calls
- Complies with 42's strict coding standards

---

## **🛠️ Features**  
- Reads from files, stdin, or other streams
- Handles buffer sizes flexibly
- Manages memory efficiently
- Returns 1 (line read), 0 (EOF), or -1 (error)

---

## **🚀 Installation**  

```bash
git clone https://github.com/flotschilein/get_next_line.git
cd get_next_line
```

---

## **📜 Example Usage**  

```c
int main() {
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

**For test.txt containing:**
```
First line
Second line
Third line
```

**Output:**  
```
First line
Second line
Third line
```

---

Made with ❤️ by **Florian**
