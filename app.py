from flask import Flask, request, jsonify
from sudoku_solver import solve_sudoku

app = Flask(sudoku)

@app.route('/solve', methods=['POST'])
def solve():
    puzzle = request.json.get('puzzle')
    solved_puzzle = solve_sudoku(puzzle)
    return jsonify({'solved_puzzle': solved_puzzle})

if __name__ == '__main__':
    app.run(debug=True)
