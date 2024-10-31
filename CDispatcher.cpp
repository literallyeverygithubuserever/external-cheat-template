#include "Memory.h"

// Initialize the static member
CDispatcher* CDispatcher::m_pDispatcher = nullptr;

CDispatcher::CDispatcher() : m_iProcessId(0), m_hProcess(nullptr) {}

CDispatcher::~CDispatcher() {
    if (m_hProcess) {
        CloseHandle(m_hProcess);
    }
}

CDispatcher* CDispatcher::Get() {
    if (m_pDispatcher == nullptr) {
        m_pDispatcher = new CDispatcher();
    }
    return m_pDispatcher;
}

void CDispatcher::Attach(std::string_view sProcessName) {
    m_iProcessId = GetProcessId(sProcessName);
    if (m_iProcessId != 0) {
        m_hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_iProcessId);
        if (m_hProcess != nullptr) {
            m_sProcessName = sProcessName;
        }
    }
}

std::string_view CDispatcher::GetProcessName() {
    return m_sProcessName;
}

unsigned __int64 CDispatcher::GetModuleBase(std::string_view sModule) {
    // Implementation to get the base address of a module
    // This will vary depending on how you plan to find the module base
    return 0;
}

bool CDispatcher::WriteProtection(unsigned __int64 uAddress, unsigned int uSize, int iProtection) {
    // Implementation to change memory protection
    return true;
}

void CDispatcher::RestoreProtection(unsigned __int64 uAddress) {
    // Implementation to restore memory protection
}

int CDispatcher::GetProcessId(std::string_view sProcessName) {
    // Implementation to get the process ID of the given process name
    return 0;
}
