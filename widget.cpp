#include "widget.h"
#include "ui_widget.h"
#include "cellTable.h"
#include "cellType.h"

QSpinBox* boxes[81];
cellTable start_grid;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::sudoku_solve(cellTable &grid, int spot_x, int spot_y)
{
    //Check if any empty spaces exist
    if( !grid.isFull() )
    {
        //If current cell is 0 and can be modified
        if( grid.contents[ spot_x ][ spot_y ].val == 0 and
            grid.contents[ spot_x ][ spot_y ].user == false )
        {
            //Loop thru all possible values
            for( int i = 1; i < 10; i++ )
                {
                    //Check if attempt "fits" in the cell
                    if( grid.checkRow( spot_x , i ) and
                        grid.checkCol( spot_y , i ) and
                        grid.checkBlock( spot_x , spot_y , i ) )
                        {
                            grid.contents[ spot_x ][ spot_y ].val = i;

                            //grid.showTable(); cout << endl; usleep( 80000 );

                            //Check if end of column
                            if( spot_x == 8 )
                            {

                                if( sudoku_solve( grid , 0 , spot_y + 1 )  == false )
                                {
                                    grid.contents[ spot_x ][ spot_y ].val = 0;
                                }

                                else
                                            {
                                    return true;
                                            }


                                        }

                            else if( spot_x < 8 )
                            {
                                //If the next cell didn't work, try again
                                if( sudoku_solve( grid , spot_x + 1 , spot_y )  == false )
                                {
                                                    grid.contents[ spot_x ][ spot_y ].val = 0;
                                                }


                                else
                                {
                                    return true;
                                }

                            }
                        }
                        }
                //None of the values worked
                return false;
            }

        //If cell cannot be modified, move on to next cell
        else if( grid.contents[ spot_x ][ spot_y ].user == true )
        {
            if( spot_x < 8 )
            {
                if( sudoku_solve( grid , spot_x + 1 , spot_y ) == false )
                {
                    return false;
                }
            }

            else if( spot_x == 8 )
            {
                if( sudoku_solve( grid , 0 , spot_y + 1 ) == false )
                {
                    return false;
                }
            }
        }
    }
    //Every cell has been filled with a value
    return true;
}

void Widget::setGridCell(cellType cell, QSpinBox* uiBox)
{
    cell.val = uiBox->value();
    if(cell.val > 0)
    {
        cell.user = true;
    }
}

void Widget::initBoxes()
{
    boxes[0] = ui->spinBox;
    boxes[1] = ui->spinBox_2;
    boxes[2] = ui->spinBox_3;
    boxes[3] = ui->spinBox_4;
    boxes[4] = ui->spinBox_5;
    boxes[5] = ui->spinBox_6;
    boxes[6] = ui->spinBox_7;
    boxes[7] = ui->spinBox_8;
    boxes[8] = ui->spinBox_9;

    boxes[9] = ui->spinBox_10;
    boxes[10] = ui->spinBox_11;
    boxes[11] = ui->spinBox_12;
    boxes[12] = ui->spinBox_13;
    boxes[13] = ui->spinBox_14;
    boxes[14] = ui->spinBox_15;
    boxes[15] = ui->spinBox_16;
    boxes[16] = ui->spinBox_17;
    boxes[17] = ui->spinBox_18;

    boxes[18] = ui->spinBox_19;
    boxes[19] = ui->spinBox_20;
    boxes[20] = ui->spinBox_21;
    boxes[21] = ui->spinBox_22;
    boxes[22] = ui->spinBox_23;
    boxes[23] = ui->spinBox_24;
    boxes[24] = ui->spinBox_25;
    boxes[25] = ui->spinBox_26;
    boxes[26] = ui->spinBox_27;

    boxes[27] = ui->spinBox_28;
    boxes[28] = ui->spinBox_29;
    boxes[29] = ui->spinBox_30;
    boxes[30] = ui->spinBox_31;
    boxes[31] = ui->spinBox_32;
    boxes[32] = ui->spinBox_33;
    boxes[33] = ui->spinBox_34;
    boxes[34] = ui->spinBox_35;
    boxes[35] = ui->spinBox_36;

    boxes[36] = ui->spinBox_37;
    boxes[37] = ui->spinBox_38;
    boxes[38] = ui->spinBox_39;
    boxes[39] = ui->spinBox_40;
    boxes[40] = ui->spinBox_41;
    boxes[41] = ui->spinBox_42;
    boxes[42] = ui->spinBox_43;
    boxes[43] = ui->spinBox_44;
    boxes[44] = ui->spinBox_45;

    boxes[45] = ui->spinBox_46;
    boxes[46] = ui->spinBox_47;
    boxes[47] = ui->spinBox_48;
    boxes[48] = ui->spinBox_49;
    boxes[49] = ui->spinBox_50;
    boxes[50] = ui->spinBox_51;
    boxes[51] = ui->spinBox_52;
    boxes[52] = ui->spinBox_53;
    boxes[53] = ui->spinBox_54;

    boxes[54] = ui->spinBox_55;
    boxes[55] = ui->spinBox_56;
    boxes[56] = ui->spinBox_57;
    boxes[57] = ui->spinBox_58;
    boxes[58] = ui->spinBox_59;
    boxes[59] = ui->spinBox_60;
    boxes[60] = ui->spinBox_61;
    boxes[61] = ui->spinBox_62;
    boxes[62] = ui->spinBox_63;

    boxes[63] = ui->spinBox_64;
    boxes[64] = ui->spinBox_65;
    boxes[65] = ui->spinBox_66;
    boxes[66] = ui->spinBox_67;
    boxes[67] = ui->spinBox_68;
    boxes[68] = ui->spinBox_69;
    boxes[69] = ui->spinBox_70;
    boxes[70] = ui->spinBox_71;
    boxes[71] = ui->spinBox_72;

    boxes[72] = ui->spinBox_73;
    boxes[73] = ui->spinBox_74;
    boxes[74] = ui->spinBox_75;
    boxes[75] = ui->spinBox_76;
    boxes[76] = ui->spinBox_77;
    boxes[77] = ui->spinBox_78;
    boxes[78] = ui->spinBox_79;
    boxes[79] = ui->spinBox_80;
    boxes[80] = ui->spinBox_81;
}

void Widget::on_pushButton_clicked()
{
    //spinBoxVal = ui->spinBox->value();
    //ui->spinBox_2->setValue(spinBoxVal);

    initBoxes();
    int count = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            start_grid.contents[i][j].val = boxes[count]->value();
            if(start_grid.contents[i][j].val > 0)
            {
                start_grid.contents[i][j].user = true;
            }
            count++;
        }
    }

    count = 0;
    sudoku_solve(start_grid,0,0);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            boxes[count++]->setValue(start_grid.contents[i][j].val);
        }
    }

}
