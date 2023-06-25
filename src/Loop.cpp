#include "Loop.h"

void Loop::Run()
{
	for (;;)
	{

		/* Read input coils */
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

		sleep(loop_time_sec);

	}
}
