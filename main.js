function solveSudoku() {
    const board = [];
    for (let i = 0; i < 9; i++) {
        const row = [];
        for (let j = 0; j < 9; j++) {
            const input = document.getElementById("cell-" + i + "-" + j);
            row.push(input.value === "" ? 0 : parseInt(input.value));
        }
        board.push(row);
    }

    fetch('/solve', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ puzzle: board }),
    })
    .then(response => response.json())
    .then(data => {
        const solvedBoard = data.solved_puzzle;
        createTable(solvedBoard);
    })
    .catch(error => console.error('Error:', error));
}
