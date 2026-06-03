const cardSymbols = ['🎨', '🎭', '🎪', '🎯', '🎲', '🎸', '🎨', '🎭', '🎪', '🎯', '🎲', '🎸'];

// Player 1 Game State
let game1 = {
    cards: [],
    flipped: [],
    matched: [],
    selectedCard: 0,
    matchedCount: 0,
    gameActive: true,
    startTime: null,
    gameBoard: null
};

// Player 2 Game State
let game2 = {
    cards: [],
    flipped: [],
    matched: [],
    selectedCard: 0,
    matchedCount: 0,
    gameActive: true,
    startTime: null,
    gameBoard: null
};

function initGames() {
    // Initialize Player 1
    game1.cards = cardSymbols.sort(() => Math.random() - 0.5);
    game1.flipped = [];
    game1.matched = [];
    game1.selectedCard = 0;
    game1.matchedCount = 0;
    game1.gameActive = true;
    game1.startTime = Date.now();
    game1.gameBoard = document.getElementById('gameBoard1');

    // Initialize Player 2
    game2.cards = cardSymbols.sort(() => Math.random() - 0.5);
    game2.flipped = [];
    game2.matched = [];
    game2.selectedCard = 0;
    game2.matchedCount = 0;
    game2.gameActive = true;
    game2.startTime = Date.now();
    game2.gameBoard = document.getElementById('gameBoard2');

    document.getElementById('p1-matches').textContent = '0';
    document.getElementById('p2-matches').textContent = '0';
    document.getElementById('p1-status').textContent = '';
    document.getElementById('p2-status').textContent = '';
    document.getElementById('winner-modal').classList.add('hidden');

    renderBoard(game1);
    renderBoard(game2);
}

function renderBoard(game) {
    game.gameBoard.innerHTML = '';
    
    game.cards.forEach((symbol, index) => {
        const card = document.createElement('button');
        card.className = 'card';
        card.dataset.index = index;
        card.dataset.symbol = symbol;
        
        // Add selection indicator
        if (game.selectedCard === index && game.gameActive) {
            if (game === game1) {
                card.classList.add('selected-p1');
            } else {
                card.classList.add('selected-p2');
            }
        }
        
        if (game.flipped.includes(index)) {
            card.classList.add('flipped');
            card.textContent = symbol;
        }
        
        if (game.matched.includes(index)) {
            card.classList.add('matched');
            card.textContent = symbol;
        }
        
        if (!game.flipped.includes(index) && !game.matched.includes(index)) {
            card.textContent = '?';
        }
        
        game.gameBoard.appendChild(card);
    });
}

function selectCard(index) {
    if (currentPlayer === 1) {
        player1SelectedCard = index;
    } else {
        player2SelectedCard = index;
    }
    renderBoard();
}

function selectCard(game, index) {
    game.selectedCard = index;
    renderBoard(game);
}

function flipCard(game) {
    const selectedIndex = game.selectedCard;
    
    if (!game.gameActive || game.flipped.includes(selectedIndex) || game.matched.includes(selectedIndex) || game.flipped.length === 2) {
        return;
    }
    
    game.flipped.push(selectedIndex);
    renderBoard(game);
    
    if (game.flipped.length === 2) {
        game.gameActive = false;
        checkMatch(game);
    }
}

function checkMatch(game) {
    const [first, second] = game.flipped;
    const firstSymbol = game.cards[first];
    const secondSymbol = game.cards[second];
    
    if (firstSymbol === secondSymbol) {
        game.matched.push(first, second);
        game.matchedCount++;
        updateMatches(game);
        game.flipped = [];
        game.gameActive = true;
        renderBoard(game);
        
        if (game.matchedCount === 6) {
            declareWinner(game);
        }
    } else {
        setTimeout(() => {
            game.flipped = [];
            game.gameActive = true;
            renderBoard(game);
        }, 1000);
    }
}

function updateMatches(game) {
    if (game === game1) {
        document.getElementById('p1-matches').textContent = game.matchedCount;
    } else {
        document.getElementById('p2-matches').textContent = game.matchedCount;
    }
}

function declareWinner(game) {
    game.gameActive = false;
    game1.gameActive = false;
    game2.gameActive = false;
    
    const elapsedTime = ((Date.now() - game.startTime) / 1000).toFixed(2);
    const playerName = game === game1 ? 'Player 1' : 'Player 2';
    
    setTimeout(() => {
        const modal = document.getElementById('winner-modal');
        document.getElementById('winner-text').textContent = `🏆 ${playerName} Wins! 🏆`;
        document.getElementById('winner-time').textContent = `Time: ${elapsedTime} seconds`;
        modal.classList.remove('hidden');
    }, 300);
}

function moveSelection(game, dx, dy) {
    const selectedIndex = game.selectedCard;
    let row = Math.floor(selectedIndex / 4);
    let col = selectedIndex % 4;
    
    row = (row + dy + 4) % 4;
    col = (col + dx + 4) % 4;
    
    const newIndex = row * 4 + col;
    selectCard(game, newIndex);
}

function resetGames() {
    initGames();
}

// Keyboard event listeners
document.addEventListener('keydown', (e) => {
    // Player 1 Controls (WASD)
    switch(e.key.toLowerCase()) {
        case 'w':
            if (game1.gameActive) {
                e.preventDefault();
                moveSelection(game1, 0, -1);
            }
            break;
        case 's':
            if (game1.gameActive) {
                e.preventDefault();
                moveSelection(game1, 0, 1);
            }
            break;
        case 'a':
            if (game1.gameActive) {
                e.preventDefault();
                moveSelection(game1, -1, 0);
            }
            break;
        case 'd':
            if (game1.gameActive) {
                e.preventDefault();
                moveSelection(game1, 1, 0);
            }
            break;
        case ' ':
            if (game1.gameActive) {
                e.preventDefault();
                flipCard(game1);
            }
            break;
    }
    
    // Player 2 Controls (Arrow Keys)
    switch(e.key) {
        case 'ArrowUp':
            if (game2.gameActive) {
                e.preventDefault();
                moveSelection(game2, 0, -1);
            }
            break;
        case 'ArrowDown':
            if (game2.gameActive) {
                e.preventDefault();
                moveSelection(game2, 0, 1);
            }
            break;
        case 'ArrowLeft':
            if (game2.gameActive) {
                e.preventDefault();
                moveSelection(game2, -1, 0);
            }
            break;
        case 'ArrowRight':
            if (game2.gameActive) {
                e.preventDefault();
                moveSelection(game2, 1, 0);
            }
            break;
        case 'Enter':
            if (game2.gameActive) {
                e.preventDefault();
                flipCard(game2);
            }
            break;
    }
});

window.addEventListener('load', initGames);