
# Java Collections Notes for Stripe Coding Interview

---

## 1. Core Collection Interfaces

| Interface | Description                                                       |
| --------- | ----------------------------------------------------------------- |
| `List`    | Ordered collection, allows duplicates (`ArrayList`, `LinkedList`) |
| `Set`     | No duplicates (`HashSet`, `TreeSet`)                              |
| `Map`     | Key-value pairs (`HashMap`, `TreeMap`)                            |
| `Deque`   | Double-ended queue (`ArrayDeque`, `LinkedList`)                   |
| `Queue`   | FIFO queue (`LinkedList`, `PriorityQueue`)                        |

---

## 2. Using `Deque`

* Supports insertion/removal from both ends.
* Can be used as a stack or queue.

### Example: Using `Deque` as Stack (LIFO)

```java
Deque<Integer> stack = new ArrayDeque<>();
stack.push(10);
stack.push(20);
System.out.println(stack.pop());  // 20
System.out.println(stack.pop());  // 10
```

### Example: Using `Deque` as Queue (FIFO)

```java
Deque<Integer> queue = new ArrayDeque<>();
queue.addLast(10);
queue.addLast(20);
System.out.println(queue.removeFirst());  // 10
System.out.println(queue.removeFirst());  // 20
```

---

## 3. Using `PriorityQueue`

* Implements a **min-heap** by default (smallest element at head).
* Can provide custom ordering with a comparator (using lambda for conciseness).

### Example: Min-Heap PriorityQueue (default)

```java
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
minHeap.add(5);
minHeap.add(1);
minHeap.add(10);
System.out.println(minHeap.poll());  // 1 (smallest)
```

### Example: Max-Heap PriorityQueue with Lambda Comparator

```java
PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
maxHeap.add(5);
maxHeap.add(1);
maxHeap.add(10);
System.out.println(maxHeap.poll());  // 10 (largest)
```

Or using method reference for Integer reverse order:

```java
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
```

---

## 4. Sorting Collections with Comparator and Lambdas

* Java 8+ supports **lambda expressions** for comparators, making code concise.
* Use `List.sort()` or `Collections.sort()` with a comparator.

### Example: Sort by natural order

```java
List<String> names = Arrays.asList("bob", "alice", "carol");
names.sort((a, b) -> a.compareTo(b));  // or simply names.sort(String::compareTo);
System.out.println(names);  // [alice, bob, carol]
```

### Example: Sort in reverse order

```java
names.sort((a, b) -> b.compareTo(a));  // reverse order
// or
names.sort(Comparator.reverseOrder());
```

### Example: Sort objects by a field with lambda

```java
class Person {
    String name;
    int age;
    Person(String name, int age) { this.name = name; this.age = age; }
    public String toString() { return name + ":" + age; }
}

List<Person> people = Arrays.asList(
    new Person("Alice", 30),
    new Person("Bob", 25),
    new Person("Carol", 35)
);

people.sort((p1, p2) -> Integer.compare(p1.age, p2.age));
System.out.println(people);  // [Bob:25, Alice:30, Carol:35]
```

Or more concisely with `Comparator.comparing`:

```java
people.sort(Comparator.comparing(p -> p.age));
```

---

## 5. Key Points to Remember for Stripe Interviews

* Prefer **lambda expressions** for comparators for clean and concise code.
* Use `Deque` (via `ArrayDeque`) when you need stack or queue with fast insert/removal on both ends.
* Use `PriorityQueue` when you need efficient min/max retrieval (heap operations).
* Remember that `PriorityQueue` is a min-heap by default; use a custom comparator for max-heap.
* When sorting objects by fields, use `Comparator.comparing(...)` or lambdas.
* Always handle **null** inputs carefully if applicable (some comparators can throw NPE).

---

## 6. Bonus: Lambda Comparator Examples Cheat Sheet

```java
// Sort integers ascending
list.sort((a, b) -> a - b);

// Sort integers descending
list.sort((a, b) -> b - a);

// Sort strings by length ascending
list.sort((a, b) -> a.length() - b.length());

// Sort objects by field (e.g., age)
list.sort(Comparator.comparing(o -> o.age));

// Chain comparators: by age then by name
list.sort(Comparator.comparing((Person p) -> p.age)
                    .thenComparing(p -> p.name));
```

