#include "Loop.h"

void Loop::Run()
{
	for (;;)
	{

		/* Read input coils */
<<<<<<< HEAD
		coils->ReadInputs();
		dbmysql->InsertInputs
			(coils->GetRes(), coils->GetLastResAmount(),
			 coils->GetStart(), coils->GetAmount());
		coils->EraseRes();

		/* Read output coils */
		coils->ReadOutputs();
		dbmysql->InsertOutputs
			(coils->GetRes(), coils->GetLastResAmount(),
			 coils->GetStart(), coils->GetAmount());
		coils->EraseRes();

		/* Read input holdings */
		holdings->ReadInputs();
		dbmysql->InsertInputs
			(holdings->GetRes(), holdings->GetLastResAmount(),
			 holdings->GetStart(), holdings->GetAmount());
		coils->EraseRes();

		/* Read output holdings */
		holdings->ReadOutputs();
		dbmysql->InsertOutputs
			(holdings->GetRes(), holdings->GetLastResAmount(),
			 holdings->GetStart(), holdings->GetAmount());
		coils->EraseRes();
=======
		if (coils->ReadInputs()) {
			dbmysql->InsertInputs
				(coils->GetRes(), coils->GetLastResAmount(),
				 coils->GetStart(), coils->GetAmount());
			coils->EraseRes();
		}

		/* Read output coils */
		if (coils->ReadOutputs()) {
			dbmysql->InsertOutputs
				(coils->GetRes(), coils->GetLastResAmount(),
				 coils->GetStart(), coils->GetAmount());
			coils->EraseRes();
		}

		/* Read input holdings */
		if (holdings->ReadInputs()) {
			dbmysql->InsertInputs
				(holdings->GetRes(), holdings->GetLastResAmount(),
				 holdings->GetStart(), holdings->GetAmount());
			coils->EraseRes();
		}

		/* Read output holdings */
		if (holdings->ReadOutputs()) {
			dbmysql->InsertOutputs
				(holdings->GetRes(), holdings->GetLastResAmount(),
				 holdings->GetStart(), holdings->GetAmount());
			coils->EraseRes();
		}
>>>>>>> 134f1da (upd)

		sleep(loop_time_sec);

	}
}
