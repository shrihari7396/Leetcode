import java.util.*;

class Spreadsheet {
    private int[][] sheet;

    public Spreadsheet(int rows) {
        sheet = new int[rows][26]; // columns fixed = 26
    }

    public void setCell(String cell, int value) {
        int col = cell.charAt(0) - 'A';
        String tmp = cell.substring(1);
        int row = Integer.parseInt(tmp) - 1;
        sheet[row][col] = value;
    }

    public void resetCell(String cell) {
        int col = cell.charAt(0) - 'A';
        String tmp = cell.substring(1);
        int row = Integer.parseInt(tmp) - 1;
        sheet[row][col] = 0;
    }

    private boolean check(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }

    public int getValue(String formula) {
        int ind = formula.indexOf('+');
        String cell1 = formula.substring(1, ind);
        String cell2 = formula.substring(ind+1);
        int first = 0, second = 0;
        if(check(cell1.charAt(0))) {
            int col = cell1.charAt(0) - 'A';
            int row = Integer.parseInt(cell1.substring(1))-1;
            first = sheet[row][col];
        } else {
            first = Integer.parseInt(cell1);
        }

        
        if(check(cell2.charAt(0))) {
            int col = cell2.charAt(0) - 'A';
            int row = Integer.parseInt(cell2.substring(1))-1;
            second = sheet[row][col];
        } else {
            second = Integer.parseInt(cell2);
        }
        return first + second;
    }

}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */
