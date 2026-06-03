# Memory Card Game

## Overview
A memory matching card game with 12 cards (6 pairs) built with HTML, CSS, and JavaScript.

## Features
- 12 cards maximum (6 matching pairs)
- Click to flip cards and find matches
- Track moves and matches
- Reset game button
- Responsive design

## How to Play
1. Click on cards to flip them
2. Try to find matching pairs
3. Match all pairs to win
4. Click Reset to play again

---

## index.html
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Memory Card Game</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h1>Memory Card Game</h1>
        <div class="stats">
            <p>Moves: <span id="moves">0</span></p>
            <p>Matches: <span id="matches">0</span>/6</p>
        </div>
        <div class="game-board" id="gameBoard"></div>
        <button class="reset-btn" onclick="resetGame()">Reset Game</button>
    </div>
    <script src="script.js"></script>
</body>
</html>
```

## style.css
```css
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body {
    font-family: 'Arial', sans-serif;
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh;
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
}

.container {
    text-align: center;
    background: white;
    padding: 30px;
    border-radius: 10px;
    box-shadow: 0 10px 30px rgba(0, 0, 0, 0.3);
}

h1 {
    color: #333;
    margin-bottom: 20px;
    font-size: 2.5em;
}

.stats {
    display: flex;
    justify-content: center;
    gap: 40px;
    margin-bottom: 30px;
    font-size: 1.2em;
    color: #555;
}

.stats p {
    margin: 0;
}

.stats span {
    font-weight: bold;
    color: #667eea;
}

.game-board {
    display: grid;
    grid-template-columns: repeat(4, 80px);
    gap: 10px;
    margin-bottom: 30px;
    justify-content: center;
}

.card {
    width: 80px;
    height: 80px;
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    border: none;
    border-radius: 8px;
    cursor: pointer;
    font-size: 2em;
    transition: all 0.3s ease;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
    display: flex;
    align-items: center;
    justify-content: center;
    color: white;
    font-weight: bold;
}

.card:hover:not(.flipped) {
    transform: translateY(-5px);
    box-shadow: 0 6px 12px rgba(0, 0, 0, 0.3);
}

.card.flipped {
    background: white;
    color: #333;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
}

.card.matched {
    background: #4caf50;
    color: white;
    cursor: not-allowed;
    pointer-events: none;
}

.reset-btn {
    padding: 12px 30px;
    font-size: 1.1em;
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    color: white;
    border: none;
    border-radius: 5px;
    cursor: pointer;
    transition: all 0.3s ease;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
}

.reset-btn:hover {
    transform: translateY(-2px);
    box-shadow: 0 6px 12px rgba(0, 0, 0, 0.3);
}

.reset-btn:active {
    transform: translateY(0);
}
```

## script.js
```javascript
const cardSymbols = ['🎨', '🎭', '🎪', '🎯', '🎲', '🎸', '🎨', '🎭', '🎪', '🎯', '🎲', '🎸'];
let cards = [];
let flipped = [];
let matched = [];
let moves = 0;
let matchedCount = 0;

function initGame() {
    cards = cardSymbols.sort(() => Math.random() - 0.5);
    flipped = [];
    matched = [];
    moves = 0;
    matchedCount = 0;
    
    document.getElementById('moves').textContent = moves;
    document.getElementById('matches').textContent = matchedCount;
    
    renderBoard();
}

function renderBoard() {
    const gameBoard = document.getElementById('gameBoard');
    gameBoard.innerHTML = '';
    
    cards.forEach((symbol, index) => {
        const card = document.createElement('button');
        card.className = 'card';
        card.dataset.index = index;
        card.dataset.symbol = symbol;
        
        if (flipped.includes(index)) {
            card.classList.add('flipped');
            card.textContent = symbol;
        }
        
        if (matched.includes(index)) {
            card.classList.add('matched');
            card.textContent = symbol;
        }
        
        if (!flipped.includes(index) && !matched.includes(index)) {
            card.textContent = '?';
        }
        
        card.addEventListener('click', () => flipCard(index));
        gameBoard.appendChild(card);
    });
}

function flipCard(index) {
    if (flipped.includes(index) || matched.includes(index) || flipped.length === 2) {
        return;
    }
    
    flipped.push(index);
    renderBoard();
    
    if (flipped.length === 2) {
        moves++;
        document.getElementById('moves').textContent = moves;
        checkMatch();
    }
}

function checkMatch() {
    const [first, second] = flipped;
    const firstSymbol = cards[first];
    const secondSymbol = cards[second];
    
    if (firstSymbol === secondSymbol) {
        matched.push(first, second);
        matchedCount++;
        document.getElementById('matches').textContent = matchedCount;
        flipped = [];
        renderBoard();
        
        if (matchedCount === 6) {
            setTimeout(() => alert(`You won! Total moves: ${moves}`), 300);
        }
    } else {
        setTimeout(() => {
            flipped = [];
            renderBoard();
        }, 1000);
    }
}

function resetGame() {
    initGame();
}

window.addEventListener('load', initGame);
```
