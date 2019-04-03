
#ifndef PROTEUS_TEST_H
#define PROTEUS_TEST_H

// --- general includes

#include "TARMProcessor.h"
#include "TMemory.h"
#include "TEmulator.h"
#include "TInterruptManager.h"
#include "TJITGeneric_Macros.h"
#include "TJITGenericROMPatch.h"

#include "K/Threads/TFiber.h"

extern TARMProcessor *CPU;
extern TMemory *MEM;
extern TInterruptManager *INT;

// --- macros

/** Accessing the Registers */
#define R0 CPU->mCurrentRegisters[0]
#define R1 CPU->mCurrentRegisters[1]
#define R2 CPU->mCurrentRegisters[2]
#define R3 CPU->mCurrentRegisters[3]
#define R4 CPU->mCurrentRegisters[4]
#define R5 CPU->mCurrentRegisters[5]
#define R6 CPU->mCurrentRegisters[6]
#define R7 CPU->mCurrentRegisters[7]
#define R8 CPU->mCurrentRegisters[8]
#define R9 CPU->mCurrentRegisters[9]
#define R10 CPU->mCurrentRegisters[10]
#define R11 CPU->mCurrentRegisters[11]
#define R12 CPU->mCurrentRegisters[12]
#define R13 CPU->mCurrentRegisters[13]
#define SP CPU->mCurrentRegisters[13]
#define R14 CPU->mCurrentRegisters[14]
#define LR CPU->mCurrentRegisters[14]
#define R15 CPU->mCurrentRegisters[15]
#define PC CPU->mCurrentRegisters[15]

/** Exit the native code to this address in the interpreter */
#define EXIT(addr) { R15 = addr+4; return nullptr; }

/** Push a value onto the stack (stmdb) */
#define PUSH(sp, w) { sp-=4; MEM->Write(sp, w); }

/** Pop a value from the stack (ldmia) */
#define POP(sp, w) { MEM->Read(sp, w); sp+=4; }

/** Reverse pop, (ldmdb) */
#define RPOP(sp, w) { sp-=4; MEM->Read(sp, w); }

/** Read a word from memory */
inline KUInt32 PEEK_W(KUInt32 addr) { KUInt32 w; MEM->Read(addr, w); return w; }

/** Write a word to memory */
#define POKE_W(addr, w) { MEM->Write(addr, w); }

#endif