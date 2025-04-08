import os

# Create results directory if it doesn't exist
RESULTS_DIR = "results"
os.makedirs(RESULTS_DIR, exist_ok=True)

# Sample sparse matrix operations
class SparseMatrix:
    def __init__(self, rows, cols, elements):
        self.rows = rows
        self.cols = cols
        self.elements = elements  # {(row, col): value}

    @staticmethod
    def from_file(filepath):
        with open(filepath, 'r') as f:
            lines = f.readlines()
        rows = int(lines[0].split('=')[1])
        cols = int(lines[1].split('=')[1])
        elements = {}
        for line in lines[2:]:
            i, j, val = eval(line.strip())
            elements[(i, j)] = val
        return SparseMatrix(rows, cols, elements)

    def to_file(self, filepath):
        with open(filepath, 'w') as f:
            f.write(f"rows={self.rows}\n")
            f.write(f"cols={self.cols}\n")
            for (i, j), val in self.elements.items():
                f.write(f"({i}, {j}, {val})\n")

    def add(self, other):
        result = self.elements.copy()
        for key, val in other.elements.items():
            result[key] = result.get(key, 0) + val
        return SparseMatrix(self.rows, self.cols, {k: v for k, v in result.items() if v != 0})

    def subtract(self, other):
        result = self.elements.copy()
        for key, val in other.elements.items():
            result[key] = result.get(key, 0) - val
        return SparseMatrix(self.rows, self.cols, {k: v for k, v in result.items() if v != 0})

    def multiply(self, other):
        if self.cols != other.rows:
            raise ValueError("Matrix dimensions do not match for multiplication")
        result = {}
        for (i, k), v in self.elements.items():
            for j in range(other.cols):
                if (k, j) in other.elements:
                    result[(i, j)] = result.get((i, j), 0) + v * other.elements[(k, j)]
        return SparseMatrix(self.rows, other.cols, {k: v for k, v in result.items() if v != 0})


def main():
    input1 = os.path.join("sample_inputs", "matrix1.txt")
    input2 = os.path.join("sample_inputs", "matrix2.txt")

    m1 = SparseMatrix.from_file(input1)
    m2 = SparseMatrix.from_file(input2)

    m1.add(m2).to_file(os.path.join(RESULTS_DIR, "addition.txt"))
    m1.subtract(m2).to_file(os.path.join(RESULTS_DIR, "subtraction.txt"))
    m1.multiply(m2).to_file(os.path.join(RESULTS_DIR, "multiplication.txt"))

    print("Operations complete. Check the 'results/' folder for outputs.")


if __name__ == "__main__":
    main()
