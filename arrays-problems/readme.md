
# 🧠 Arrays – Complete Pattern Guide for Coding Interviews

> 🚀 Pattern-based + Interview-focused guide to mastering Array problems

---

## 📌 Table of Contents

- 🔥 Why Arrays Matter
- 🧩 Core Patterns (with Interview Approach)
- ⚡ Pattern Decision Tree
- 🧠 Mental Models
- 🛠️ Core Snippets
- 📊 Time Complexity Cheat Sheet
- 🚨 Common Mistakes
- 🎯 Must-Do Problems (with Links)
- 📚 Revision Strategy

---

## 🔥 Why Arrays Matter

- Foundation of DSA
- Most asked topic in interviews
- Builds patterns for:
  - Sliding Window
  - Prefix Sum
  - Two Pointers
  - Greedy
  - Hashing

---

# 🧩 Core Patterns (Interview Approach)

---

## 🟢 1. Prefix Sum

### 🧠 When to Think?
- “Subarray sum = k”
- Negative numbers present ❗
- Count subarrays

---

### 🪜 Approach

| Level | Idea |
|------|------|
| Brute | Generate all subarrays → check sum (O(n²)) |
| Optimal | Prefix sum + HashMap (O(n)) |

---

### 💡 Core Logic

```

prefix[current] - prefix[previous] = k
prefix[previous] = prefix[current] - k

````

---

### ⚙️ Key Snippet

```cpp
sum += num;

if (mp.count(sum - k))
    count += mp[sum - k];

mp[sum]++;
````

---

### 🔗 Practice Problems

* Subarray Sum Equals K
* Continuous Subarray Sum (LC 523)
* [https://www.geeksforgeeks.org/problems/subarray-sum-equals-k/1](https://www.geeksforgeeks.org/problems/subarray-sum-equals-k/1)

---

## 🔵 2. Sliding Window

### 🧠 When to Think?

* “Longest / shortest subarray”
* All elements **non-negative**

---

### 🪜 Approach

| Level   | Idea                |
| ------- | ------------------- |
| Brute   | Check all subarrays |
| Better  | Maintain window     |
| Optimal | Expand + shrink     |

---

### ⚙️ Key Snippet

```cpp
while (condition breaks) {
    left++;
}
```

---

### 🔗 Practice Problems

* Longest Substring Without Repeating Characters (LC 3)
* Minimum Size Subarray Sum (LC 209)

---

## 🟡 3. Two Pointers

### 🧠 When to Think?

* Sorted array
* Pair / container problems

---

### 🪜 Approach

| Level   | Idea                    |
| ------- | ----------------------- |
| Brute   | Check all pairs (O(n²)) |
| Optimal | Two pointers (O(n))     |

---

### 💡 Key Insight

* Move pointer based on condition
* Eliminate impossible cases

---

### ⚙️ Key Snippet

```cpp
if (height[left] < height[right])
    left++;
else
    right--;
```

---

### 🔗 Practice Problems

* Two Sum II - Input Array Is Sorted
* Container With Most Water

---

## 🟠 4. Hashing

### 🧠 When to Think?

* Need O(1) lookup
* Duplicates / frequency
* Sequence detection

---

### 🪜 Approach

| Level   | Idea          |
| ------- | ------------- |
| Brute   | Nested loops  |
| Optimal | HashSet / Map |

---

### ⚙️ Key Snippet

```cpp
unordered_set<int> st(nums.begin(), nums.end());
```

---

### 🔗 Practice Problems

* Longest Consecutive Sequence
* Two Sum (LC 1)

---

## 🔴 5. Kadane’s Algorithm

### 🧠 When to Think?

* Maximum / minimum subarray

---

### 🪜 Approach

| Level   | Idea                 |
| ------- | -------------------- |
| Brute   | All subarrays        |
| Optimal | Drop negative prefix |

---

### ⚙️ Key Snippet

```cpp
curr = max(nums[i], curr + nums[i]);
```

---

### 🔗 Practice Problems

* Maximum Subarray

---

## 🟣 6. Sorting + Greedy

### 🧠 When to Think?

* Intervals
* Ordering matters

---

### 🔗 Practice Problems

* Merge Intervals (LC 56)
* Non-overlapping Intervals (LC 435)

---

# ⚡ Pattern Decision Tree

```
Subarray + sum?
    → Prefix Sum

Longest / shortest?
    → Positive → Sliding Window
    → Negative → Prefix Sum

Sorted array?
    → Two Pointers

Need fast lookup?
    → Hashing
```

---

## 🧠 Mental Models

| Problem Type      | Think             |
| ----------------- | ----------------- |
| Subarray sum      | Prefix difference |
| Longest substring | Expand + shrink   |
| Pair sorted       | Two ends          |
| Sequence          | Start points      |
| Max sum           | Drop negatives    |

---

## 🛠️ Core Snippets (Quick Revision)

```cpp
// Prefix sum
if (mp.count(sum - k)) count += mp[sum - k];

// Two pointers
if (a[left] < a[right]) left++;

// Kadane
curr = max(a[i], curr + a[i]);
```

---

## 📊 Time Complexity Cheat Sheet

| Pattern        | Time | Space |
| -------------- | ---- | ----- |
| Prefix Sum     | O(n) | O(n)  |
| Sliding Window | O(n) | O(1)  |
| Two Pointers   | O(n) | O(1)  |
| Hashing        | O(n) | O(n)  |
| Kadane         | O(n) | O(1)  |

---

## 🚨 Common Mistakes

* ❌ Sliding window with negatives
* ❌ Forgetting `mp[0] = 1`
* ❌ Not identifying pattern early
* ❌ Overusing brute force

---

## 🎯 Must-Do Problems

* Two Sum
* Maximum Subarray
* Subarray Sum Equals K
* Longest Consecutive Sequence
* Container With Most Water

---

## 📚 Revision Strategy

1. Identify pattern
2. Recall approach (Brute → Optimal)
3. Apply template
4. Practice 1–2 problems

---

## 🚀 Final Thought

> 💡 “Interviews are not about solving problems —
> they are about recognizing patterns.”
