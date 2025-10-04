# 📘 Java File I/O and JSON/CSV Processing — Complete Notes

---

## 📂 Part 1: File Reading and Writing in Java

---

### 📥 Reading Files

#### 1. BufferedReader (Efficient for large text files)

```java
import java.io.*;

public class ReadWithBufferedReader {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
````

#### 2. Scanner (Useful for parsing tokens)

```java
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ReadWithScanner {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("input.txt"))) {
            while (sc.hasNextLine()) {
                System.out.println(sc.nextLine());
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
```

#### 3. FileInputStream (Binary files)

```java
import java.io.*;

public class ReadBinaryFile {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("file.bin")) {
            int b;
            while ((b = fis.read()) != -1) {
                System.out.print((char) b);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

#### 4. Files.readAllLines (Java NIO)

```java
import java.nio.file.*;
import java.util.*;

public class ReadUsingNIO {
    public static void main(String[] args) throws Exception {
        List<String> lines = Files.readAllLines(Paths.get("input.txt"));
        lines.forEach(System.out::println);
    }
}
```

---

### 📤 Writing Files

#### 1. BufferedWriter

```java
import java.io.*;

public class WriteWithBufferedWriter {
    public static void main(String[] args) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"))) {
            bw.write("Hello, world!");
            bw.newLine();
            bw.write("Another line.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

#### 2. FileOutputStream

```java
import java.io.*;

public class WriteBinaryFile {
    public static void main(String[] args) {
        try (FileOutputStream fos = new FileOutputStream("output.bin")) {
            byte[] data = "Hello!".getBytes();
            fos.write(data);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

#### 3. Files.write (NIO)

```java
import java.nio.file.*;
import java.util.*;

public class WriteWithNIO {
    public static void main(String[] args) throws IOException {
        List<String> lines = List.of("Line 1", "Line 2");
        Files.write(Paths.get("output.txt"), lines);
    }
}
```

---

## 📂 Part 2: File Path Handling

---

### Using java.io.File

```java
import java.io.File;

public class FilePathExample {
    public static void main(String[] args) {
        File file = new File("data.txt");
        System.out.println("Absolute path: " + file.getAbsolutePath());
        System.out.println("Exists: " + file.exists());
        System.out.println("Is file: " + file.isFile());
    }
}
```

### Using java.nio.file.Path

```java
import java.nio.file.*;

public class PathExample {
    public static void main(String[] args) {
        Path path = Paths.get("folder", "data.txt");
        System.out.println("Path: " + path.toAbsolutePath());
    }
}
```

---

## 📂 Part 3: JSON Processing with GSON

---

### 📌 GSON Setup (Maven)

```xml
<dependency>
    <groupId>com.google.code.gson</groupId>
    <artifactId>gson</artifactId>
    <version>2.10.1</version>
</dependency>
```

---

### 📄 Reading Simple JSON to POJO

#### JSON (person.json)

```json
{
  "name": "Alice",
  "age": 30
}
```

#### POJO

```java
public class Person {
    String name;
    int age;
}
```

#### Reading JSON

```java
import com.google.gson.Gson;
import java.io.FileReader;

public class ReadSimpleJson {
    public static void main(String[] args) throws Exception {
        Gson gson = new Gson();
        Person person = gson.fromJson(new FileReader("person.json"), Person.class);
        System.out.println(person.name + " - " + person.age);
    }
}
```

---

### 📄 Filtering Developers From JSON

#### JSON (employees.json)

```json
{
  "company": "Tech Corp",
  "employees": [
    { "id": 1, "name": "Alice", "role": "Developer", "salary": 60000 },
    { "id": 2, "name": "Bob", "role": "Manager", "salary": 80000 },
    { "id": 3, "name": "Charlie", "role": "Developer", "salary": 65000 }
  ]
}
```

#### Code

```java
import com.google.gson.*;
import java.io.*;

public class FilterDevelopers {
    public static void main(String[] args) throws Exception {
        JsonObject root = JsonParser.parseReader(new FileReader("employees.json")).getAsJsonObject();
        JsonArray employees = root.getAsJsonArray("employees");

        for (JsonElement e : employees) {
            JsonObject emp = e.getAsJsonObject();
            if ("Developer".equals(emp.get("role").getAsString())) {
                System.out.println("Developer: " + emp.get("name").getAsString());
            }
        }
    }
}
```

---

### ✏️ Update JSON (Increase Salary)

```java
import com.google.gson.*;
import java.io.*;

public class UpdateSalaries {
    public static void main(String[] args) throws Exception {
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        JsonObject root = JsonParser.parseReader(new FileReader("employees.json")).getAsJsonObject();
        JsonArray employees = root.getAsJsonArray("employees");

        for (JsonElement e : employees) {
            JsonObject emp = e.getAsJsonObject();
            double salary = emp.get("salary").getAsDouble();
            emp.addProperty("salary", salary * 1.10); // Increase 10%
        }

        try (Writer writer = new FileWriter("updated_employees.json")) {
            gson.toJson(root, writer);
        }
    }
}
```

---

### 🧱 Create JSON Dynamically

```java
import com.google.gson.*;

public class CreateJson {
    public static void main(String[] args) {
        JsonObject employee = new JsonObject();
        employee.addProperty("name", "Daisy");
        employee.addProperty("role", "HR");
        employee.addProperty("salary", 50000);

        JsonArray employees = new JsonArray();
        employees.add(employee);

        JsonObject root = new JsonObject();
        root.addProperty("company", "NewTech");
        root.add("employees", employees);

        System.out.println(new GsonBuilder().setPrettyPrinting().create().toJson(root));
    }
}
```

---

## 📂 Part 4: CSV File Processing

---

### 📥 Reading CSV Manually

**CSV (data.csv)**

```
id,name,age
1,Alice,30
2,Bob,40
```

```java
import java.io.*;

public class ReadCSV {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("data.csv"))) {
            br.readLine(); // skip header
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                System.out.println("Name: " + parts[1]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

### 📤 Writing CSV Manually

```java
import java.io.*;

public class WriteCSV {
    public static void main(String[] args) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("output.csv"))) {
            bw.write("id,name,age");
            bw.newLine();
            bw.write("1,Charlie,25");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

## ✅ Summary Table

| Task                    | Method/Class         | Suitable For               |
| ----------------------- | -------------------- | -------------------------- |
| Read text file          | `BufferedReader`     | Line-by-line, efficient    |
| Read binary file        | `FileInputStream`    | Raw byte access            |
| Write to file           | `BufferedWriter`     | Appending text             |
| Read whole file (small) | `Files.readAllLines` | Small files into memory    |
| JSON read/write         | `GSON`               | Full-featured JSON support |
| Parse CSV               | `BufferedReader`     |                            |
