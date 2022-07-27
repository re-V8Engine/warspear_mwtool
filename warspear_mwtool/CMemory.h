#pragma once

class CMemory
{
private:
	HANDLE handle;
	DWORD pid;
	HWND hwnd = NULL;

	Offset tOffset;
	Address tAddress;

public:
	CMemory();
	~CMemory();
	CMemory(HANDLE _handle, DWORD _pid) { handle = _handle; pid = _pid; }
	void Update();
	void UpdateAddress();
	DWORD GetBaseAddress();
	void UpdateHWND();
	DWORD getPid() { return pid; }
	Address* getAddress() { return &tAddress; }
	void setHWND(HWND hwnd) { this->hwnd = hwnd; }
	void SendKey(WPARAM key);
	template <typename ReadType> bool Read(ReadType* Buffer, DWORD Address)
	{
		return ReadProcessMemory(handle, (LPVOID)(Address), Buffer, sizeof(ReadType), 0);
	}
	template <typename WriteType> void Write(WriteType* Data, DWORD Address)
	{
		WriteProcessMemory(handle, (LPVOID)(Address), Data, sizeof(WriteType), 0);
	}
	template <typename ReadType> ReadType ReadOffset(DWORD Address, int num_args, ...)
	{
		DWORD dwOffset;
		DWORD firstAddress;
		ReadType value;

		ReadProcessMemory(handle, (LPVOID)(Address), &firstAddress, sizeof(DWORD), 0);

		if (num_args == 0)
		{
			return firstAddress;
		}

		va_list ap;

		va_start(ap, num_args);
		for (int i = 0; i < num_args; i++)
		{
			dwOffset = va_arg(ap, DWORD);
			if (i != num_args - 1)
			{
				ReadProcessMemory(handle, (LPVOID)(firstAddress + dwOffset), &firstAddress, sizeof(DWORD), 0);
			}
		}

		ReadProcessMemory(handle, (LPVOID)(firstAddress + dwOffset), &value, sizeof(ReadType), 0);
		return value;
	}
	template <typename WriteType> void WriteOffset(WriteType* Data, DWORD Address, int num_args, ...)
	{
		DWORD dwOffset;
		DWORD firstAddress;

		if (num_args == 0)
		{
			WriteProcessMemory(handle, (LPVOID)(Address), Data, sizeof(WriteType), 0);
			return;
		}

		ReadProcessMemory(handle, (LPVOID)(Address), &firstAddress, sizeof(DWORD), 0);


		va_list ap;

		va_start(ap, num_args);
		for (int i = 0; i < num_args; i++)
		{
			dwOffset = va_arg(ap, DWORD);
			if (i != num_args - 1)
			{
				ReadProcessMemory(handle, (LPVOID)(firstAddress + dwOffset), &firstAddress, sizeof(DWORD), 0);
			}
		}

		WriteProcessMemory(handle, (LPVOID)(firstAddress + dwOffset), Data, sizeof(WriteType), 0);
	}
	
	static const wstring exeName;
	static const DWORD dwMainOffset = 0x54E710;
};

