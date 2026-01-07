# GPT-7

Mr. Kokos just got his dream job at *AnihtoAI* and his first task is to develop an experimental image generation system for GPT-7.

The goal of the image generation system is to convert rough **K**×**K** pixel sketches (provided by the users) into realistic **K**×**K** pixel images. The input sketches and output images of the system are all represented by **K**×**K** matrices of integers. For the purposes of this problem, a **K**×**K** matrix is simply a **K**×**K** 2D array with **K** rows and **K** columns.

<div align="center">
<img src="Images/gpt7_pipeline.png" width="400">
</div>

For this system to work, there are **M transformation layers**, indexed from **0** to **M-1**, each represented by a **K**×**K** matrix of integers.

The image generation system works as follows:
-	A sketch is given as a **K**×**K**  matrix, **InputMatrix**. To generate the output image, represented as a **K**×**K** matrix, **OutputMatrix**, the system selects a consecutive range of transformation layers, from index **L** to index **R** (**0** ≤ **L** ≤ **R** < **M**), inclusive, and applies them on the **InputMatrix** as an alternating sum.

- Formally,

    **OutputMatrix = InputMatrix + (Layer[L] - Layer[L+1] + Layer[L+2] - Layer[L+3] + ... ± Layer[R])**

-	**Note:** The first layer (**Layer[L]**) is always **added**. The operations then **alternate between subtraction and addition**. 

<br>

### **Matrix Addition and Subtraction Definition**

Addition and subtraction of matrices of the same size is defined **element-wise**. That is, the operation is applied independently to each corresponding cell of the matrices. 

Example of a **2**×**2** matrix addition:

<img src="Images/matrix_addition_latex.png" width="400">

<div style="page-break-after: always;"></div>


### **Your Task**

Mr. Kokos needs your help to test the system he developed.

You are given,
- **M** matrices indexed from **0** to **Μ-1** (the layers of the system).
- **N** matrices indexed from **0** to **Ν-1** (the sketches), and for each matrix you are given two integers **L** and **R** (the range parameters of the sketches).
- A matrix representing the desired generated image, **TargetMatrix**.

For each sketch, **InputMatrix[i]**, first calculate the corresponding generated image, **OutputMatrix[i]**, as described above. Then, define the **error** of a sketch, **Error[i]**, as the sum of squared differences between **OutputMatrix[i]** and the **TargetMatrix**:

<img src="Images/error_latex.png" width="500">

Your task is to determine which sketch produces the generated image with the **minimum error**, and the **value of that minimum error**. If multiple sketches have the same minimum error, choose the one with the smallest index (the one that was given first in the input).

<br>

## **Input**

<hr style="border: 0; border-top: 0.1px solid #ddd;">

-	The first line contains three integers **N, M,** and **K**.
- The next **M**×**K** lines contain **M**, **K**×**K** matrices, indexed from **0** to **M-1**, representing the transformation layers of the system.
- The next **N**×(**K**+**1**) lines contain **N** sketches, indexed from **0** to **N-1**, each represented by:
  - One line with the range parameters **L** and **R** of the sketch.
  - Followed by a **K**×**K** matrix, representing the **InputMatrix** of the sketch.
- The next **K** lines contain a **K**×**K** matrix, representing the **TargetMatrix**.

**Note:** Each **K**×**K** matrix in the input consists of **K** lines, with **K** integers per line. The j-th integer in the i-th line corresponds to the (i, j) element of the matrix.

<br>

## **Output**

<hr style="border: 0; border-top: 0.1px solid #ddd;">

Output two integers:
1.	The **(0-based) index** of the sketch with the **minimum error**.
2.	The corresponding **minimum error value**.

<div style="page-break-after: always;"></div>

## **Constraints**

- 1 ≤ N ≤ 10<sup>5</sup>
- 1 ≤ M ≤ 10<sup>5</sup>
- 1 ≤ K ≤ 10
- Every element of the matrices is an integer whose absolute value **does not exceed 10<sup>3</sup>**

## **Subtasks**

- **Subtask 1 (5 points):** N = 1, M ≤ 100, K = 1
- **Subtask 2 (5 points):** N = 1, M = 1, K ≤ 10
- **Subtask 3 (25 points):** N ≤ 10<sup>3</sup>, M ≤ 10<sup>3</sup>, K ≤ 10
- **Subtask 4 (20 points):** N ≤ 10<sup>5</sup>, M ≤ 10<sup>5</sup>, K = 1, L = 0 for all sketches
- **Subtask 5 (30 points):** N ≤ 10<sup>5</sup>, M ≤ 10<sup>5</sup>, K = 1
- **Subtask 6 (15 points):** N ≤ 10<sup>5</sup>, M ≤ 10<sup>5</sup>, K ≤ 10

## **Example**

### **Example Input**

```txt
2 3 2

1 4
7 0

3 2
5 1

0 6
2 8

0 2
2 1
0 2

1 1
3 3
2 9

4 5
6 7
```

**Note:** Empty lines in the example input were added only for clarity purposes. There are no empty lines in the actual input.

<div style="page-break-after: always;"></div>

### **Example Output**

```txt
1 14
```

## **Explanation**

#### Input:

<pre style="margin:10; padding:0;">
  <code style="padding:0; margin:0;">
  N = 2, M = 3, K = 2
  </code>
</pre>

<table>
  <tr>
    <td style="vertical-align:top; padding-right:12px;">
      <code>Layer[0]</code>
      <pre style="margin:6px 0 0 0;">⎡ 1  4 ⎤
⎣ 7  0 ⎦</pre>
    </td>
    <td style="vertical-align:top; padding-right:10px;">
      <code>Layer[1]</code>
      <pre style="margin:6px 0 0 0;">⎡ 3  2 ⎤
⎣ 5  1 ⎦</pre>
    </td>
    <td style="vertical-align:top;">
      <code>Layer[2]</code>
      <pre style="margin:6px 0 0 0;">⎡ 0  6 ⎤
⎣ 2  8 ⎦</pre>
    </td>
    <td style="vertical-align:top;">
      <code>TargetMatrix</code>
      <pre style="margin:6px 0 0 0;">⎡ 4  5 ⎤
⎣ 6  7 ⎦</pre>
    </td>
  </tr>
</table>

<table>
  <tr>
    <td style="vertical-align:top; padding-right:20px;">
      <code>Input[0]</code>
      <pre style="margin:6px 0 0 0;">⎡ 2  1 ⎤,  L = 0, R = 2
⎣ 0  2 ⎦</pre>
    </td>
    <td style="vertical-align:top;">
      <code>Input[1]</code>
      <pre style="margin:6px 0 0 0;">⎡ 3  3 ⎤,  L = 1, R = 1
⎣ 2  9 ⎦</pre>
    </td>
  </tr>
</table>

#### Generated Images:

<pre style="margin:6px 0 0 0;"><code>OutputMatrix[0] = ⎡ 2  1 ⎤ + ⎡ 1  4 ⎤ - ⎡ 3  2 ⎤ + ⎡ 0  6 ⎤ = ⎡ 0  9 ⎤
                  ⎣ 0  2 ⎦   ⎣ 7  0 ⎦   ⎣ 5  1 ⎦   ⎣ 2  8 ⎦   ⎣ 4  9 ⎦

OutputMatrix[1] = ⎡ 3  3 ⎤ + ⎡ 3  2 ⎤ = ⎡ 6  5 ⎤
                  ⎣ 2  9 ⎦   ⎣ 5  1 ⎦   ⎣ 7 10 ⎦</code></pre>

#### Error:

<pre style="margin:0px 0 0 0;">
<code> • Error[0] = (0−4)² + (9−5)² + (4−6)² + (9−7)² = 40
 • Error[1] = (6−4)² + (5−5)² + (7−6)² + (10−7)² = 14 </code>
</pre>

#### Therefore,

The index of the sketch with the minimum error is **1**, and its error value is **14**.