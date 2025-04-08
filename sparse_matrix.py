import os

class SparseMatrix:
    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.data = {}  # Dictionary to store non-zero values keyed by (row, col)

    @staticmethod
    def from_file(filepath):
        try:
            with open(filepath, 'r') as f:
                lines = [line.strip() for line in f if line.strip()]

            if not (lines[0].startswith("rows=") and lines[1].startswith("cols=")):
                raise ValueError("Missing 'rows=' or 'cols=' headers")

            rows = int(lines[0].split('=')[1])
            cols = int(lines[1].split('=')[1])

            matrix = SparseMatrix(rows, cols)
            for line in lines[2:]:
                if not (line.startswith("(") and line.endswith(")")):
                    raise ValueError("Input file has wrong format")
                content = line[1:-1].split(',')
                if len(content) != 3:
                    raise ValueError("Each entry must have 3 values")
                r, c, v = content
                if '.' in r or '.' in c or '.' in v:
                    raise ValueError("Floating point values are not allowed")
                matrix.set(int(r), int(c), int(v))

            return matrix
        except Exception as e:
            raise ValueError(f"Error reading file {filepath}: {e}")

    def set(self, row, col, value):
        if row < 0 or row >= self.rows or col < 0 or col >= self.cols:
            raise IndexError("Index out of bounds")
        if value != 0:
            self.data[(row, col)] = value

    def get(self, row, col):
        return self.data.get((row, col), 0)

    def add(self, other):
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError("Matrix dimensions must match for addition")
        result = SparseMatrix(self.rows, self.cols)
        for key in set(self.data.keys()).union(other.data.keys()):
            result.set(*key, self.get(*key) + other.get(*key))
        return result

    def subtract(self, other):
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError("Matrix dimensions must match for subtraction")
        result = SparseMatrix(self.rows, self.cols)
        for key in set(self.data.keys()).union(other.data.keys()):
            result.set(*key, self.get(*key) - other.get(*key))
        return result

    def multiply(self, other):
        if self.cols != other.rows:
            raise ValueError("Invalid dimensions for multiplication")
        result = SparseMatrix(self.rows, other.cols)
        for (i, k), v in self.data.items():
            for j in range(other.cols):
                result.set(i, j, result.get(i, j) + v * other.get(k, j))
        return result

    def to_string(self):
        lines = [f"rows={self.rows}", f"cols={self.cols}"]
        for (r, c), v in sorted(self.data.items()):
            lines.append(f"({r}, {c}, {v})")
        return "\n".join(lines)


def main():
    input_dir = 'sample_inputs'
    result_dir = 'results'
    os.makedirs(result_dir, exist_ok=True)

    input1 = os.path.join(input_dir, 'matrix1.txt')
    input2 = os.path.join(input_dir, 'matrix2.txt')

    print("Select an operation:")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    choice = input("Enter choice (1/2/3): ").strip()

    try:
        m1 = SparseMatrix.from_file(input1)
        m2 = SparseMatrix.from_file(input2)

        if choice == '1':
            result = m1.add(m2)
            with open(os.path.join(result_dir, 'addition.txt'), 'w') as f:
                f.write(result.to_string())
            print("Addition complete. Check 'results/addition.txt'")
        elif choice == '2':
            result = m1.subtract(m2)
            with open(os.path.join(result_dir, 'subtraction.txt'), 'w') as f:
                f.write(result.to_string())
            print("Subtraction complete. Check 'results/subtraction.txt'")
        elif choice == '3':
            result = m1.multiply(m2)
            with open(os.path.join(result_dir, 'multiplication.txt'), 'w') as f:
                f.write(result.to_string())
            print("Multiplication complete. Check 'results/multiplication.txt'")
        else:
            print("Invalid choice.")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == '__main__':
    main()
