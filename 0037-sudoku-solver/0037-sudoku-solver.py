class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def isValid(r, c, k):
            for i in range(9):
                # Check row and column
                if board[i][c] == k or board[r][i] == k:
                    return False
                
                # Check 3x3 subgrid
                subgrid_row = 3 * (r // 3) + i // 3
                subgrid_col = 3 * (c // 3) + i % 3
                if board[subgrid_row][subgrid_col] == k:
                    return False
            return True    

        def fill(r, c):
            # If we have reached the end of the board, return True
            if r == 9:
                return True
            
            # Move to the next row if the column is completed
            if c == 9:
                return fill(r + 1, 0)
            
            # If the current cell is empty, try placing numbers
            if board[r][c] == '.':
                for k in range(1, 10):
                    if isValid(r, c, str(k)):
                        board[r][c] = str(k)
                        
                        # If the board is solved with this number, return True
                        if fill(r, c + 1):
                            return True
                        
                        # If the placement didn't work, reset the cell and try the next number
                        board[r][c] = '.'
                
                return False
            
            # If the cell is already filled, move to the next column
            return fill(r, c + 1)

        # Start solving the board from the first cell
        fill(0, 0)