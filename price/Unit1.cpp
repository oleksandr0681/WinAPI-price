//---------------------------------------------------------------------------
// �������� "Price" ���������� ��� ���������� ���� ���������.
// �������� "Price" ��������������� �� ������ "�� �".
// �� ����� �� �������� "Price" �������� ������: ���� ����������.
// ͳ���, ��� ������, �� �� ����� �������� �������� ��� ��������.
// ��� ���������� ������������� ������������ ��'�����-�����������
// �������������.

#include <windows.h>
#include <math.h>
#include <stdio.h>            
#include "dialog.h"
// ���������� �������� ���������� ����.
#include "struct_price.h"
// ��������� price, ��������� ���� ���������.

BOOL CALLBACK dialog_function (HWND, UINT, WPARAM, LPARAM);
// ³����� ������� ���������� ����.


//---------------------------------------------------------------------------


WINAPI WinMain
(
	HINSTANCE program_description,
	// ���������� (���������), ������� Windows ����������� ����������
	// ��������� (����������).
	HINSTANCE prev_program_description,
	// ���� �������� ������� ��� ������������� ������ �� Windows 3.x, ��� ��
	// ������������� ��� ������������� ����������� ����������� ����������
	// ���������. � Win32 ���� �������� �� ������������ � ������� ������
	// ��������� ������� ��������.
	LPSTR cmd_line,
	// ��������� �� ������, � ������� ���������� ��������� ���������
	// (����������), ���� ��� �������� � ������ ��������� ������.
	int nCmdShow
	// ����� ��������, ������� ����� ���� �������� ������� ShowWindow.
)
{
	static HINSTANCE program_description_for_dialog_box;
	// ����������� ����������. ���������� ���������. ������������ �
	// ������� DialogBox().
	program_description_for_dialog_box=GetModuleHandle(NULL);
	// ������� GetModuleHandle ��������� ���������� ���������� ������.
	// ���� �������� - ����� (NULL), GetModuleHandle ����������
	// ���������� �����, ������������, ����� ������� ���������� �������
	// (.EXE ����).
	DialogBox
	// ������� ������ � ������� �� ����� ��������� ���������� ����.
	(
		program_description_for_dialog_box,
		// ���������� ��������� (����������� ����������).
		"price",
		// ��� ������� ����������� ����.
		NULL,
		// ���������� ���� ���������, � ������� ����������� ����������
		// ����.
		(DLGPROC)dialog_function
		// ������� ������� ��� ����������� ����.
	);
	return 0;
}
//---------------------------------------------------------------------------

BOOL CALLBACK dialog_function
// ³����� ������� ���������� ����.
(
	HWND dialog_window_description,
	// �������� �������� ���������� ����������� ���� "������ ���������
	// ������������ �������", ����������� ���������.
	UINT message,
	// �������� ��������� ������������� ���������.
	WPARAM wparam,
	LPARAM lparam
	// ������ � �������� ��������� �������� �������������� ����������,
	// ������� ����������� �������� � ����������� �� ���� �����������
	// ���������.
)
{
	HWND help_description=0;
	static char text[3072]="";
	static float prime_cost=3729.60, profit=559.44, TAC=857.81, tax=900.0;
	static float excise=0, sale_increase=0, trade_increase=0;
	static float production_price=0;
	bool input_range=true;
	price calculation_1
	(
		3729.60,
		// ���������� ���������, ���.
		559.44,
		// ��������, ���.
		857.81,
		// ������� �� ������ ������� (���), ���.
		900.0,
		// ���� ������� �� ������ � ��������, ���.
		0.0,
		// �������� ���, ���.
		0.0,
		// ������-������� ��������, ���.
		0.0
		// ���������� ��������, ���.
	);
	static char file[1024]="";
	static OPENFILENAME file_name;
	bool file_name_present=false;
	static bool calculation_execute=false;
	HANDLE file_handle;
	DWORD number_to_write=0;
	DWORD number_written=0;
	static char program_dir[1024];
	/*
	help_description	- ���������� ���� ���������� ����������.	
	text				- ������ ��� �������� ������.
	prime_cost			- ���������� ���������, ���.
	profit				- ��������, ���.
	TAC					- ������� �� ������ ������� (���), ���.
	tax					- ���� ������� �� ������ � ��������, ���.
	excise				- �������� ���, ���.
	sale_increase		- �������-������� ��������, ���.
	trade_increase		- ���������� ��������, ���.
	production_price	- ���� ���������, ���.
	input_range			- ��������� �������� �� ���������� �������.
	calculation_1		- ��'��� ��������� price ��� ����������
						  ���� ���������, ���.
	file				- ������ ��� ������������ ����������� ����
							"Save As".
	file_name 			- ��������� ���� FILENAME ��� ������������
							����������� ���� "Save As".
	file_name_present	- ��������� ����������� ����� �����.
	calculation_execute	- ��������� ���������� �������.	
	file_handle			- ���������� (���������) �����.
	number_to_write		- ����� ������������ ������.
	number_written		- ����������� ������ ���������� ������.
	program_dir			- ����� ��� ��������� ����� �� ��������.
	*/
	switch(message)
	// ������ ����������� ���������� �������� switch ��� ����������� ����,
	// ����� ��������� �������� � ��� ��� ������������.
	// ��� ���� ���������, �� �������������� � ���������, ���� ������
	// ��������� ������� �������, ������ �������� FALSE.
	// ����� �������, ����������� ����� ��� ������ ��� ��� ���������,
	// ������� ��������� � ������������� ���������.
	{
	case WM_INITDIALOG:
	// ��������� � �������� ����������� ����.
		// ������������� ��������� file_name.
		file_name.lStructSize=sizeof(OPENFILENAME);
		// �������� ���������� ����� ��������� � ������.
		file_name.hwndOwner=dialog_window_description;
		// ���������� ����, ���������� ���������� ����.
		file_name.lpstrFilter="��������� ����� *.txt\0*.txt\0��� �����\0"
		"*.*\0\0";
		// ��������� �� �����, � ������� ��������� ���� ����-���������������
		// (null-terminated) ����� ��� �������.
		file_name.lpstrFile=file;
		// ��������� �� �����, ������� �������� ������ ����, ��� �
		// ���������� �����, ��������� � ���� "��� �����" �������
		// GetSaveFileName.
		file_name.nMaxFile=sizeof(file);
		// ���������� ������ ������, �� ������� ��������� �������� lpstrFile.
		file_name.lpstrDefExt="txt";
		// ��������� �� �����, � ������� ��������� ���������� �� ���������.
		GetCurrentDirectory
		// ������� ������ �������� �������. � ������ ������� ������� ������
		// �������, � ����� �������� ��������.
		(
			sizeof(program_dir),
			// ����� ������.
			program_dir
			// �������� (���������) �� �����.
			// �������, �� ����������� ��������.
		);
		return TRUE;
	case WM_COMMAND:
	// ��������� ����������, ����� ������������ �������� �������
	//����������� ����.
		switch (LOWORD(wparam))
		{
		case ID_CALCULATION:
		// ��������� � ������� ������ "�����������".
			GetDlgItemText
			// ������� �������� ����� �� ������ �������� ����������.
			// ������ �� ������ �������, ������ ���, ���� ����� ���
			// ����������� �����.
			(
				dialog_window_description,
				// ���������� ����������� ����.
				ID_PRIME_COST,
				// ������������� �������� ����������, �� �������� ��������
				// ������.
				// ���������� ���������, ���.
				text,
				// ������, � ������� ���������� �����.
				20
				// ����� ������.
			);
			prime_cost=atof(text);
			// ������� ��������� ������ � ������ ����� � ��������� ������.
			GetDlgItemText
			// ������� �������� ����� �� ������ �������� ����������.
			// ������ �� ������ �������, ������ ���, ���� ����� ���
			// ����������� �����.
			(
				dialog_window_description,
				// ���������� ����������� ����.
				ID_PROFIT,
				// ������������� �������� ����������, �� �������� ��������
				// ������.
				// ��������, ���.
				text,
				// ������, � ������� ���������� �����.
				20
				// ����� ������.
			);
			profit=atof(text);
			// ������� ��������� ������ � ������ ����� � ��������� ������.
			GetDlgItemText
			// ������� �������� ����� �� ������ �������� ����������.
			// ������ �� ������ �������, ������ ���, ���� ����� ���
			// ����������� �����.
			(
				dialog_window_description,
				// ���������� ����������� ����.
				ID_TAC,
				// ������������� �������� ����������, �� �������� ��������
				// ������.
				// ������� �� ������ ������� (���), ���.
				text,
				// ������, � ������� ���������� �����.
				20
				// ����� ������.
			);
			TAC=atof(text);
			// ������� ��������� ������ � ������ ����� � ��������� ������.
			GetDlgItemText
			// ������� �������� ����� �� ������ �������� ����������.
			// ������ �� ������ �������, ������ ���, ���� ����� ���
			// ����������� �����.
			(
				dialog_window_description,
				// ���������� ����������� ����.
				ID_TAX,
				// ������������� �������� ����������, �� �������� ��������
				// ������.
				// ���� ������� �� ������ � ��������, ���.
				text,
				// ������, � ������� ���������� �����.
				20
				// ����� ������.
			);
			tax=atof(text);
			// ������� ��������� ������ � ������ ����� � ��������� ������.
			GetDlgItemText
			// ������� �������� ����� �� ������ �������� ����������.
			// ������ �� ������ �������, ������ ���, ���� ����� ���
			// ����������� �����.
			(
				dialog_window_description,
				// ���������� ����������� ����.
				ID_EXCISE,
				// ������������� �������� ����������, �� �������� ��������
				// ������.
				// �������� ���, ���.
				text,
				// ������, � ������� ���������� �����.
				20
				// ����� ������.
			);
			excise=atof(text);
			// ������� ��������� ������ � ������ ����� � ��������� ������.
			GetDlgItemText
			// ������� �������� ����� �� ������ �������� ����������.
			// ������ �� ������ �������, ������ ���, ���� ����� ���
			// ����������� �����.
			(
				dialog_window_description,
				// ���������� ����������� ����.
				ID_SALE_INCREASE,
				// ������������� �������� ����������, �� �������� ��������
				// ������.
				// ������-������� ��������, ���.
				text,
				// ������, � ������� ���������� �����.
				20
				// ����� ������.
			);
			sale_increase=atof(text);
			// ������� ��������� ������ � ������ ����� � ��������� ������.
			GetDlgItemText
			// ������� �������� ����� �� ������ �������� ����������.
			// ������ �� ������ �������, ������ ���, ���� ����� ���
			// ����������� �����.
			(
				dialog_window_description,
				// ���������� ����������� ����.
				ID_TRADE_INCREASE,
				// ������������� �������� ����������, �� �������� ��������
				// ������.
				// ���������� ��������, ���.
				text,
				// ������, � ������� ���������� �����.
				20
				// ����� ������.
			);
			trade_increase=atof(text);
			// ������� ��������� ������ � ������ ����� � ��������� ������.
			if (prime_cost<0 || prime_cost>100000000)
			// �������� ��������� �������� � ���� "����������
			// ���������, ���.".
			{
				input_range=false;
				sprintf
				(
					text,
					"���������� ��������� ����� 0 ��� "
					"����� 100000000 ���."
				);
				MessageBox
				(
					dialog_window_description,
					// ���������� ����������� ����.
					text,
					// ��������� �� ������, ���������� ����� ���������.
					"������� �����",
					// ��������� �� ������, ���������� ����� ���������
					// ����������� ����.
					MB_ICONWARNING
					// �������� ����� ���������� � ���� ������ �
					// ���������� ����, � ����� ������� �������� �����������.
				);
			}
			if (profit<0 || profit>100000000)
			// �������� ��������� �������� � ���� "��������, ���.".
			{
				input_range=false;
				sprintf
				(
					text,
					"�������� ������ 0 ��� ������ 100000000 ���."
				);
				MessageBox
				(
					dialog_window_description,
					// ���������� ����������� ����.
					text,
					// ��������� �� ������, ���������� ����� ���������.
					"������� �����",
					// ��������� �� ������, ���������� ����� ���������
					// ����������� ����.
					MB_ICONWARNING
					// �������� ����� ���������� � ���� ������ �
					// ���������� ����, � ����� ������� �������� �����������.
				);
			}
			if (TAC<0 || TAC>100000000)
			// �������� ��������� �������� � ���� "������� ��
			// ������ ������� (���), ���.".
			{
				input_range=false;
				sprintf
				(
					text,
					"������� �� ������ ������� (���) "
					"������ 0 ��� ������ 100000000 ���."
				);
				MessageBox
				(
					dialog_window_description,
					// ���������� ����������� ����.
					text,
					// ��������� �� ������, ���������� ����� ���������.
					"������� �����",
					// ��������� �� ������, ���������� ����� ���������
					// ����������� ����.
					MB_ICONWARNING
					// �������� ����� ���������� � ���� ������ �
					// ���������� ����, � ����� ������� �������� �����������.
				);
			}
			if (tax<0 || tax>100000000)
			// �������� ��������� �������� � ���� "���� ������� ��
			// ������ � ��������, ���.".
			{
				input_range=false;
				sprintf
				(
					text,
					"���� ������� �� ������ � �������� "
					"����� 0 ��� ����� 100000000 ���."
				);
				MessageBox
				(
					dialog_window_description,
					// ���������� ����������� ����.
					text,
					// ��������� �� ������, ���������� ����� ���������.
					"������� �����",
					// ��������� �� ������, ���������� ����� ���������
					// ����������� ����.
					MB_ICONWARNING
					// �������� ����� ���������� � ���� ������ �
					// ���������� ����, � ����� ������� �������� �����������.
				);
			}
			if (excise<0 || excise>100000000)
			// �������� ��������� �������� � ���� "�������� ���, ���.".
			{
				input_range=false;
				sprintf
				(
					text,
					"�������� ��� ������ 0 ��� "
					"������ 100000000 ���."
				);
				MessageBox
				(
					dialog_window_description,
					// ���������� ����������� ����.
					text,
					// ��������� �� ������, ���������� ����� ���������.
					"������� �����",
					// ��������� �� ������, ���������� ����� ���������
					// ����������� ����.
					MB_ICONWARNING
					// �������� ����� ���������� � ���� ������ �
					// ���������� ����, � ����� ������� �������� �����������.
				);
			}
			if (sale_increase<0 || sale_increase>100000000)
			// �������� ��������� �������� � ���� "������-�������
			// ��������, ���.".
			{
				input_range=false;
				sprintf
				(
					text,
					"������-������� �������� ����� 0 ��� "
					"����� 100000000 ���."
				);
				MessageBox
				(
					dialog_window_description,
					// ���������� ����������� ����.
					text,
					// ��������� �� ������, ���������� ����� ���������.
					"������� �����",
					// ��������� �� ������, ���������� ����� ���������
					// ����������� ����.
					MB_ICONWARNING
					// �������� ����� ���������� � ���� ������ �
					// ���������� ����, � ����� ������� �������� �����������.
				);
			}
			if (trade_increase<0 || trade_increase>100000000)
			// �������� ��������� �������� � ���� "����������
			// ��������, ���.".
			{
				input_range=false;
				sprintf
				(
					text,
					"���������� �������� ����� 0 ��� "
					"����� 100000000 ���."
				);
				MessageBox
				(
					dialog_window_description,
					// ���������� ����������� ����.
					text,
					// ��������� �� ������, ���������� ����� ���������.
					"������� �����",
					// ��������� �� ������, ���������� ����� ���������
					// ����������� ����.
					MB_ICONWARNING
					// �������� ����� ���������� � ���� ������ �
					// ���������� ����, � ����� ������� �������� �����������.
				);
			}
			if (input_range==true)
			// �������� �������� ����������. ������ ����������� ���� ���
			// ���������� ����� ���������� ��������.
			{
				// ���������� ���� ���������, ���.
				calculation_1.set_prime_cost(prime_cost);
				// ��������� ��'���� calculation_1 ����������
				// ���������, ���.
				calculation_1.set_profit(profit);
				// ��������� ��'���� calculation_1 ��������, ���.
				calculation_1.set_TAC(TAC);
				// ��������� ��'���� calculation_1 �������
				// �� ������ ������� (���), ���.
				calculation_1.set_tax(tax);
				// ��������� ��'���� calculation_1 ����� �������
				// �� ������ � ��������, ���.
				calculation_1.set_excise(excise);
				// ��������� ��'���� calculation_1 ��������� �����, ���.
				calculation_1.set_sale_increase(sale_increase);
				// ��������� ��'���� calculation_1
				// ������-������� ��������, ���.
				calculation_1.set_trade_increase(trade_increase);
				// ��������� ��'���� calculation_1 ����������
				// ��������, ���.
				production_price=calculation_1.calculation();
				// ���������� ���� ���������, ���.
				gcvt
				// ������� ����������� ����� � ��������� ������ � ������.
				(
					production_price,
					20,
					text
				);
				SetDlgItemText
				// ������� ���������� ����� � ������� ����������.
				(
					dialog_window_description,
					// ���������� ����������� ����.
					ID_PRICE,
					// ������������� �������� ����������, � �������
					// ������������ ������.
					text
					// ������, �� ������� ������������ �����.
				);
				calculation_execute=true;				
			}
			return true;
		case ID_SAVE:
		// ��������� � ������� ������ "�������� ����������".
			strcpy(file, "");
			// ������� �������� ���������� ������ � ��������� �����. �
			// ������ ������ ������� ������� ���������� ���������� file.
			if (calculation_execute==true)
			// �������� ��������� ����������.
			{
				file_name_present=GetSaveFileName(&file_name);
				// ������� ������ ����������� ���������� ���� "Save As".
			}
			if (file_name_present==true)
			// �������� ����������� ����� �����.
			{
				file_handle=CreateFile
				// ������� ������ ��������� �� ����e ���������� (����).
				(
					file_name.lpstrFile, // ��������� �� ��� �����.
					//(����������).
					GENERIC_READ | GENERIC_WRITE,
					// ��������� ���������� ������ �� ������ � ������.
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					// ����� ������ �� ������ � ������ � ������� �����.
					// �� ���� ���� ����� �������� ��� �������������
					// ������������� ����������� ����������.
					NULL,
					// ������� ������������ ����������. �� ���� ���
					// ����������� ����� �������� �������� ���������
					// ����� ���������.
					CREATE_ALWAYS,
					// �������� ��������� �� �������� ������ �����. ���� ����
					// ����������, �� �� ����� �����������.
					FILE_ATTRIBUTE_NORMAL,
					// �������� FILE_ATTRIBUTE_NORMAL ���������� �����
					//����������� ��������.
					NULL
					// ������� �� ������������.
				);
				sprintf
				// ������� ���������� � ������ text ��������� �������
				// ����������� ��������� ������ ���� ������ ���������.
				(
					text,
					"���������� ���� ���������.\n\n"
					"ֳ�� ��������� P, ���,\n\n P=PC+Pf+TAC+T+E+SI+TI,\n\n"
					"��\n"
					"PC - ���������� ���������, ���;\n"
					"Pf - ��������, ���;\n"
					"TAC - ������� �� ������ ������� (���), ���;\n"
					"T - ���� ������� �� ������ � ��������, ���;\n"
					"E - �������� ���, ���;\n"
					"SI - �������-������� ��������, ���;\n"
					"TI - ���������� ��������, ���.\n\n"
					"P=%f, ���;\n\n"
					"PC=%f, ���;\n"
					"Pf=%f, ���;\n"
					"TAC=%f, ���;\n"
					"T=%f, ���;\n"
					"E=%f, ���;\n"
					"SI=%f, ���;\n"
					"TI=%f, ���.\n",
					production_price, prime_cost, profit, TAC, tax, excise,
					sale_increase, trade_increase
				);
				number_to_write=strlen(text);
				WriteFile
				// ������ � ���� ���������� �������.
				(
					file_handle,	// ���������� (���������) �����.
					text,			// ��������� �� ����� - ������ ����������
									// ������ � ����.
					number_to_write,// ����� ������������ ������.
					&number_written,// ����������� ������ ���������� ������.
					NULL			// ���� ������ ������� � �����.
				);
				CloseHandle(file_handle);
				// ������� ����������� ��������� �� ���������� (����).
			}
			return true;
		case ID_HELP:
		// ��������� � ������� ������ "������".
			SetCurrentDirectory(program_dir);
			// ������� ���������� �������� �������. � ������ ������� ����������
			// �������� ������� �������� (� ������ ������). �������
			// ����������� ��� ������ ����������� ���� ����������
			// ���������� ����������.
			help_description=FindWindow
			// ������� �������� ���������� ����.
			(
				"HH Parent",
				// ��� ����.
				"price"
				// ����� � ��������� ����.
			);
			if (help_description==0)
			// �������� ������������� ���� ���������� ����������.
			{
				WinExec
				// ������� ������������ ������ ������� ��������.
				(
					"hh.exe price.chm",
					// �������� ������� ���������.
					SW_RESTORE
					// ����� ����������� ����, � ������� ��������� ������
					// ��������.
				);
			}
			else
        	// ������� ���� ���������� ����������.
			{
				ShowWindow
            	// ������� ���������� ���� �� ������.
				(
					help_description,
					// ���������� ����.
                	SW_RESTORE
					// �������� ����������, � ����� ���� ����� ��������
					// ���� �������� ShowWindow.
				);
            	SetForegroundWindow (help_description);
				// ������� ���������� ���� �� �������� ����.    
			}
			return true;
		case ID_EXIT:
		// ��������� � ������� ������ "�����".
			help_description=FindWindow
			// ������� �������� ���������� ����.
			(
				"HH Parent",
				// ��� ����.
				"price"
				// ����� � ��������� ����.
			);
			if (help_description!=0)
			// �������� ������������� ���� ���������� ����������.
			// ������� ���� ���������� ����������.
			{
				SendMessage
				// ������� �������� ��������� ���������� ����.
				(
					help_description,
					// ���������� ����-����������.
					WM_CLOSE,
					// ��������� ���������� ���� � ���, ��� ��� ������
					// ���� �������.
					0,
					// ������ �������� ���������.
					0
					// ������ �������� ���������.
				);
			}
			InvalidateRect
			// ������� ���������� ��������� WM_PAINT.
			(
				NULL,
				// ���������� ����, � �������� ��������� ����������� ������.
				// ���� ���� �������� ����� NULL, �� ������� ��������� �
				// �������������� ��� ���� ���������.
				NULL,
				// ��������� �� ��������� ���� RECT, ���������� ����������
				// ���������� ��������������, ������� ����������� �
				// ������������ �������. ���� ���� �������� ����� NULL, ��
            	// � ������������ ������� ����������� ��� ���������� �������.
				FALSE
				// ����, ������������, ����� �� ��������� ��� ������������
				//�������.
			);
			EndDialog
			// ������� ��������� ���������� ���� � ��������� ����������
			// ������� DialogBox().
			(
				dialog_window_description,
				// ���������� ����������� ����.
				0
				// ��������, ������� ��������� ������� DialogBox.
			);
			return TRUE;
		case IDCANCEL:
		// ��������� � ������� ��������� ������ Alt+F4.
			help_description=FindWindow
			// ������� �������� ���������� ����.
			(
				"HH Parent",
				// ��� ����.
				"price"
				// ����� � ��������� ����.
			);
			if (help_description!=0)
			// �������� ������������� ���� ���������� ����������.
			// ������� ���� ���������� ����������.
			{
				SendMessage
				// ������� �������� ��������� ���������� ����.
				(
					help_description,
					// ���������� ����-����������.
					WM_CLOSE,
					// ��������� ���������� ���� � ���, ��� ��� ������
					// ���� �������.
					0,
					// ������ �������� ���������.
					0
					// ������ �������� ���������.
				);
			}
			InvalidateRect
			// ������� ���������� ��������� WM_PAINT.
			(
				NULL,
				// ���������� ����, � �������� ��������� ����������� ������.
				// ���� ���� �������� ����� NULL, �� ������� ��������� �
				// �������������� ��� ���� ���������.
				NULL,
				// ��������� �� ��������� ���� RECT, ���������� ����������
				// ���������� ��������������, ������� ����������� �
				// ������������ �������. ���� ���� �������� ����� NULL, ��
            	// � ������������ ������� ����������� ��� ���������� �������.
				FALSE
				// ����, ������������, ����� �� ��������� ��� ������������
				//�������.
			);
			EndDialog
			// ������� ��������� ���������� ���� � ��������� ����������
			// ������� DialogBox().
			(
				dialog_window_description,
				// ���������� ����������� ����.
				0
				// ��������, ������� ��������� ������� DialogBox.
			);
			return TRUE;

		}
		return TRUE;		
	default:
		break;
	}
	return FALSE;
	// ��� ���� ���������, �� �������������� � ���������, ���� ������
	// ��������� ������� �������, ������ �������� FALSE.
}
