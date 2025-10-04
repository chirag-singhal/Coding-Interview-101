# Comprehensive Java File I/O and JSON Processing Notes

---

## Part 1: File Reading and Writing in Java

### Reading Files

#### 1. Using BufferedReader (Efficient for text files)

```java
try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
    String line;
    while ((line = br.readLine()) != null) {
        System.out.println(line);
    }
} catch (IOException e) {
    e.printStackTrace();
}
````

#### 2. Using Scanner

```java
try (Scanner sc = new Scanner(new File("input.txt"))) {
    while (sc.hasNextLine()) {
        System.out.println(sc.nextLine());
    }
} catch (FileNotFoundException e) {
    e.printStackTrace();
}
```

#### 3. Using FileInputStream (for binary files)

```java
try (FileInputStream fis = new FileInputStream("file.bin")) {
    int b;
    while ((b = fis.read()) != -1) {
        System.out.print((char) b);
    }
} catch (IOException e) {
    e.printStackTrace();
}
```

#### 4. Using Files.readAllLines (Java NIO)

```java
List<String> lines = Files.readAllLines(Paths.get("input.txt"));
lines.forEach(System.out::println);
```

---

### Writing Files

#### 1. Using BufferedWriter

```java
try (BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"))) {
    bw.write("Hello, world!");
    bw.newLine();
    bw.write("Another line.");
} catch (IOException e) {
    e.printStackTrace();
}
```

#### 2. Using FileOutputStream (binary)

```java
try (FileOutputStream fos = new FileOutputStream("output.bin")) {
    byte[] data = "Hello!".getBytes();
    fos.write(data);
} catch (IOException e) {
    e.printStackTrace();
}
```

#### 3. Using Files.write (Java NIO)

```java
List<String> data = List.of("Line 1", "Line 2");
Files.write(Paths.get("output.txt"), data);
```

---

## Part 2: Working with File Paths

### Using java.io.File

```java
File file = new File("data.txt");
System.out.println("Absolute Path: " + file.getAbsolutePath());
System.out.println("Exists? " + file.exists());
System.out.println("Is File? " + file.isFile());
```

### Using java.nio.file.Path

```java
Path path = Paths.get("folder", "data.txt");
System.out.println("Absolute Path: " + path.toAbsolutePath());
```

---

## Part 3: JSON Processing with GSON

### Setup Maven Dependency

```xml
<dependency>
    <groupId>com.google.code.gson</groupId>
    <artifactId>gson</artifactId>
    <version>2.10.1</version>
</dependency>
```

---

### Basic JSON Parsing (Simple POJO)

#### Example JSON (`person.json`)

```json
{
  "name": "Alice",
  "age": 30
}
```

#### Java POJO

```java
public class Person {
    String name;
    int age;
}
```

#### Reading JSON

```java
Gson gson = new Gson();
Person person = gson.fromJson(new FileReader("person.json"), Person.class);
System.out.println(person.name + " - " + person.age);
```

---

### Reading JSON Arrays into Collections

#### JSON Array (`users.json`)

```json
[
  { "name": "Alice", "age": 30 },
  { "name": "Bob", "age": 25 },
  { "name": "Charlie", "age": 28 }
]
```

#### Java Class (`User.java`)

```java
public class User {
    public String name;
    public int age;

    @Override
    public String toString() {
        return name + " - " + age;
    }
}
```

#### Reading JSON Array as Collection

```java
Type collectionType = new TypeToken<Collection<User>>(){}.getType();
Collection<User> users = gson.fromJson(new FileReader("users.json"), collectionType);

for (User user : users) {
    System.out.println(user);
}
```

---

### Complex Nested JSON to Nested POJO

#### JSON (`company.json`)

```json
{
  "companyName": "Tech Corp",
  "address": {
    "street": "123 Tech Street",
    "city": "Innovation City"
  },
  "employees": [
    { "name": "Alice", "age": 30, "skills": ["Java", "Gson", "Spring"] },
    { "name": "Bob", "age": 25, "skills": ["JavaScript", "React"] }
  ]
}
```

#### Nested POJO Classes

```java
import java.util.List;

public class Company {
    String companyName;
    Address address;
    List<Employee> employees;
}

public class Address {
    String street;
    String city;
}

public class Employee {
    String name;
    int age;
    List<String> skills;
}
```

#### Deserialize

```java
Company company = gson.fromJson(new FileReader("company.json"), Company.class);
System.out.println(company.companyName);
System.out.println(company.address.city);
for (Employee emp : company.employees) {
    System.out.println(emp.name + " knows " + emp.skills);
}
```

---

### Filtering JSON Elements (Manual with JsonObject/JsonArray)

```java
JsonObject root = JsonParser.parseReader(new FileReader("employees.json")).getAsJsonObject();
JsonArray employees = root.getAsJsonArray("employees");

for (JsonElement e : employees) {
    JsonObject emp = e.getAsJsonObject();
    if ("Developer".equals(emp.get("role").getAsString())) {
        System.out.println(emp.get("name").getAsString());
    }
}
```

---

### Modifying JSON (Example: Increase Salary by 10%)

```java
for (JsonElement e : employees) {
    JsonObject emp = e.getAsJsonObject();
    double salary = emp.get("salary").getAsDouble();
    emp.addProperty("salary", salary * 1.10);
}
try (Writer writer = new FileWriter("updated_employees.json")) {
    new GsonBuilder().setPrettyPrinting().create().toJson(root, writer);
}
```

---

### Creating JSON Programmatically

```java
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
```

---

### Writing Java Objects to JSON

```java
List<User> users = List.of(
    new User("Alice", 30),
    new User("Bob", 25)
);

try (Writer writer = new FileWriter("users_out.json")) {
    gson.toJson(users, writer);
}
```

---

## Part 4: CSV File Processing (Manual)

### Reading CSV

```java
try (BufferedReader br = new BufferedReader(new FileReader("data.csv"))) {
    br.readLine(); // skip header
    String line;
    while ((line = br.readLine()) != null) {
        String[] parts = line.split(",");
        System.out.println("Name: " + parts[1] + ", Age: " + parts[2]);
    }
}
```

### Writing CSV

```java
try (BufferedWriter bw = new BufferedWriter(new FileWriter("output.csv"))) {
    bw.write("id,name,age");
    bw.newLine();
    bw.write("1,Charlie,25");
}
```

---

## Summary Table

| Task             | Method/Class              | Use Case                  |
| ---------------- | ------------------------- | ------------------------- |
| Read text file   | `BufferedReader`          | Line-by-line text reading |
| Read binary file | `FileInputStream`         | Binary data               |
| Write to file    | `BufferedWriter`          | Text output               |
| Read whole file  | `Files.readAllLines`      | Small text files          |
| Parse JSON       | `Gson`                    | Simple and complex JSON   |
| Parse JSON Array | `TypeToken<List<T>>`      | Deserialize arrays        |
| Read nested JSON | Nested POJO Classes       | Complex structures        |
| Modify JSON      | `JsonObject` manipulation | Dynamic edits             |
| CSV parsing      | `BufferedReader` + split  | Simple CSV files          |

---

# End of Notes

