Program SIGMA_Converter_V1.1.5.exe language=x86:LE:32:default

// FUNCTION FUN_00401b70 @ 00401b70

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * __thiscall FUN_00401b70(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  local_10 = param_2;
  local_c = 1;
  *param_1 = std::exception::vftable;
  *(undefined8 *)(param_1 + 1) = 0;
  ___std_exception_copy(&local_10,param_1 + 1);
  *param_1 = std::runtime_error::vftable;
  return param_1;
}



// FUNCTION FUN_00401bd0 @ 00401bd0

undefined4 * __thiscall FUN_00401bd0(undefined4 *param_1,byte param_2)

{
  *param_1 = std::exception::vftable;
  ___std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    FUN_00541f12(param_1,0xc);
  }
  return param_1;
}



// FUNCTION FUN_00401c20 @ 00401c20

undefined4 * __thiscall FUN_00401c20(undefined4 *param_1,int param_2)

{
  *param_1 = std::exception::vftable;
  *(undefined8 *)(param_1 + 1) = 0;
  ___std_exception_copy(param_2 + 4,param_1 + 1);
  *param_1 = std::runtime_error::vftable;
  return param_1;
}



// FUNCTION FUN_00401c60 @ 00401c60

void __fastcall FUN_00401c60(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1[1] != 0) {
    HidD_FreePreparsedData(param_1[1]);
    param_1[1] = 0;
  }
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
    *param_1 = 0;
  }
  if (7 < (uint)param_1[0x23]) {
    iVar2 = param_1[0x1e];
    iVar1 = param_1[0x23] * 2;
    uVar4 = iVar1 + 2;
    iVar3 = iVar2;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar2 + -4);
      uVar4 = iVar1 + 0x25;
      if (0x1f < (iVar2 - iVar3) - 4U) goto LAB_00401d78;
    }
    FUN_00541f12(iVar3,uVar4);
  }
  param_1[0x22] = 0;
  param_1[0x23] = 7;
  *(undefined2 *)(param_1 + 0x1e) = 0;
  if (7 < (uint)param_1[0x1d]) {
    iVar2 = param_1[0x18];
    iVar1 = param_1[0x1d] * 2;
    uVar4 = iVar1 + 2;
    iVar3 = iVar2;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar2 + -4);
      uVar4 = iVar1 + 0x25;
      if (0x1f < (iVar2 - iVar3) - 4U) goto LAB_00401d78;
    }
    FUN_00541f12(iVar3,uVar4);
  }
  param_1[0x1c] = 0;
  param_1[0x1d] = 7;
  *(undefined2 *)(param_1 + 0x18) = 0;
  if (7 < (uint)param_1[0x17]) {
    iVar2 = param_1[0x12];
    iVar1 = param_1[0x17] * 2;
    uVar4 = iVar1 + 2;
    iVar3 = iVar2;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar2 + -4);
      uVar4 = iVar1 + 0x25;
      if (0x1f < (iVar2 - iVar3) - 4U) {
LAB_00401d78:
                    /* WARNING: Subroutine does not return */
        FUN_0054734f();
      }
    }
    FUN_00541f12(iVar3,uVar4);
  }
  param_1[0x16] = 0;
  param_1[0x17] = 7;
  *(undefined2 *)(param_1 + 0x12) = 0;
  return;
}



// FUNCTION FUN_00401d80 @ 00401d80

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall FUN_00401d80(undefined4 *param_1,LPCWSTR param_2)

{
  short sVar1;
  char cVar2;
  HANDLE pvVar3;
  int iVar4;
  short *psVar5;
  bool bVar6;
  undefined8 local_314;
  undefined4 local_30c;
  short local_308;
  undefined1 local_306 [254];
  short local_208;
  undefined1 local_206 [254];
  short local_108;
  undefined1 local_106 [254];
  uint local_8;
  
  local_8 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  pvVar3 = CreateFileW(param_2,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (pvVar3 == (HANDLE)0xffffffff) {
    iVar4 = FUN_00402410();
    return iVar4;
  }
  *param_1 = pvVar3;
  cVar2 = HidD_GetPreparsedData(pvVar3,param_1 + 1);
  if ((cVar2 == '\0') || (iVar4 = HidP_GetCaps(param_1[1],param_1 + 2), iVar4 == 0)) {
LAB_00401f07:
    iVar4 = FUN_00402410();
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  else {
    _memset(&local_108,0,0x100);
    cVar2 = HidD_GetProductString(*param_1,&local_108,0x100);
    if (cVar2 == '\0') goto LAB_00401f07;
    psVar5 = &local_108;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_004021d0(&local_108,(int)psVar5 - (int)local_106 >> 1);
    _memset(&local_208,0,0x100);
    cVar2 = HidD_GetManufacturerString(*param_1,&local_208,0x100);
    if (cVar2 == '\0') goto LAB_00401f07;
    psVar5 = &local_208;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_004021d0(&local_208,(int)psVar5 - (int)local_206 >> 1);
    _memset(&local_308,0,0x100);
    cVar2 = HidD_GetSerialNumberString(*param_1,&local_308,0x100);
    if (cVar2 != '\0') {
      psVar5 = &local_308;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_004021d0(&local_308,(int)psVar5 - (int)local_306 >> 1);
    }
  }
  local_30c = 0;
  local_314 = 0;
  cVar2 = HidD_GetAttributes(*param_1,&local_314);
  if (cVar2 == '\0') {
    iVar4 = FUN_00402410();
  }
  else {
    if ((local_314._4_2_ == 0x46d) && (local_314._6_2_ == -0x3da0)) {
      if (*(short *)((int)param_1 + 10) == 1) {
        bVar6 = *(short *)(param_1 + 2) == 4;
LAB_00401f8c:
        if (bVar6) goto LAB_00401f9c;
      }
    }
    else if ((local_314._4_2_ == 0xeb7) && (local_314._6_2_ == 0xe07)) {
      bVar6 = *(short *)((int)param_1 + 10) == 1;
      goto LAB_00401f8c;
    }
    iVar4 = FUN_00402400();
  }
  if (iVar4 < 0) {
    return iVar4;
  }
LAB_00401f9c:
  HidD_SetNumInputBuffers(*param_1,2);
  return 0;
}



// FUNCTION FUN_00401fc0 @ 00401fc0

undefined8 * __thiscall FUN_00401fc0(undefined4 *param_1,undefined8 *param_2)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  void *_Dst;
  char *pcVar4;
  undefined1 local_20 [12];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0055ff7e;
  local_10 = ExceptionList;
  uVar3 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = 0;
  *param_2 = 0;
  uVar1 = *(ushort *)(param_1 + 4);
  *(undefined4 *)((int)param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  *(uint *)((int)param_2 + 4) = (uint)uVar1;
  _Dst = (void *)FUN_00405265((uint)uVar1,uVar3);
  *(void **)param_2 = _Dst;
  _memset(_Dst,0,*(size_t *)((int)param_2 + 4));
  local_8 = 0;
  local_14 = 1;
  if (*(int *)((int)param_2 + 4) == 0) {
    pcVar4 = "index out of range";
  }
  else {
    **(undefined1 **)param_2 = 0xf1;
    cVar2 = HidD_GetFeature(*param_1,*(undefined4 *)param_2,*(undefined2 *)(param_1 + 4));
    if (cVar2 != '\0') {
      ExceptionList = local_10;
      return param_2;
    }
    pcVar4 = "HidD_GetFeature failed";
  }
  FUN_00401b70(pcVar4);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_005badf0);
}



// FUNCTION FUN_00402090 @ 00402090

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00402090(undefined4 *param_1,undefined1 param_2,undefined4 *param_3)

{
  undefined1 *_Dst;
  uint _Size;
  undefined1 local_30 [12];
  undefined4 *local_24;
  undefined1 local_20 [4];
  longlong local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055ffad;
  local_10 = ExceptionList;
  local_14 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Size = (uint)*(ushort *)(param_1 + 4);
  local_24 = param_3;
  if (_Size < (uint)param_3[1]) {
    FUN_00401b70("Buffer too big");
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_005badf0);
  }
  local_1c = (ulonglong)*(ushort *)(param_1 + 4) << 0x20;
  _Dst = (undefined1 *)FUN_00405265(_Size,local_14);
  local_1c = CONCAT44(local_1c._4_4_,_Dst);
  _memset(_Dst,0,_Size);
  local_8 = 0;
  FUN_00543940(_Dst + 1,*local_24,local_24[1]);
  _memset(_Dst + local_24[1],0,(uint)*(ushort *)(param_1 + 4) - local_24[1]);
  if (_Size != 0) {
    *_Dst = param_2;
    HidD_SetFeature(*param_1,_Dst,*(undefined2 *)(param_1 + 4));
    thunk_FUN_005473a0(_Dst);
    ExceptionList = local_10;
    return;
  }
  FUN_00401b70("index out of range");
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_30,&DAT_005badf0);
}



// FUNCTION guard_check_icall @ 004021a0

/* guard_check_icall */

void __cdecl guard_check_icall(void)

{
  return;
}



// FUNCTION FUN_004021b0 @ 004021b0

void __fastcall FUN_004021b0(int *param_1)

{
  if (*param_1 != 0) {
    thunk_FUN_005473a0(*param_1);
    *param_1 = 0;
  }
  return;
}



// FUNCTION FUN_004021d0 @ 004021d0

uint * __thiscall FUN_004021d0(uint *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar1 = param_1[5];
  if (param_3 <= uVar1) {
    puVar6 = param_1;
    if (7 < uVar1) {
      puVar6 = (uint *)*param_1;
    }
    param_1[4] = param_3;
    FUN_00543940(puVar6,param_2,param_3 * 2);
    *(undefined2 *)(param_3 * 2 + (int)puVar6) = 0;
    return param_1;
  }
  if (param_3 < 0x7fffffff) {
    uVar7 = param_3 | 7;
    if (uVar7 < 0x7fffffff) {
      if (0x7ffffffe - (uVar1 >> 1) < uVar1) {
        uVar7 = 0x7ffffffe;
      }
      else {
        uVar5 = (uVar1 >> 1) + uVar1;
        if (uVar7 < uVar5) {
          uVar7 = uVar5;
        }
      }
    }
    else {
      uVar7 = 0x7ffffffe;
    }
    uVar5 = -(uint)(0xfffffffe < uVar7) | uVar7 + 1;
    if (uVar5 < 0x80000000) {
      uVar5 = uVar5 * 2;
      if (uVar5 < 0x1000) {
        if (uVar5 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = FUN_0040526e(uVar5);
        }
      }
      else {
        if (uVar5 + 0x23 <= uVar5) goto LAB_00402318;
        iVar3 = FUN_0040526e(uVar5 + 0x23);
        if (iVar3 == 0) goto LAB_00402322;
        uVar5 = iVar3 + 0x23U & 0xffffffe0;
        *(int *)(uVar5 - 4) = iVar3;
      }
      param_1[5] = uVar7;
      param_1[4] = param_3;
      FUN_00543940(uVar5,param_2,param_3 * 2);
      *(undefined2 *)(param_3 * 2 + uVar5) = 0;
      if (7 < uVar1) {
        uVar2 = *param_1;
        uVar7 = uVar1 * 2 + 2;
        uVar4 = uVar2;
        if (0xfff < uVar7) {
          uVar4 = *(uint *)(uVar2 - 4);
          uVar7 = uVar1 * 2 + 0x25;
          if (0x1f < (uVar2 - uVar4) - 4) goto LAB_00402322;
        }
        FUN_00541f12(uVar4,uVar7);
      }
      *param_1 = uVar5;
      return param_1;
    }
LAB_00402318:
    FUN_004023d0();
  }
  FUN_004023f0();
LAB_00402322:
                    /* WARNING: Subroutine does not return */
  FUN_0054734f();
}



// FUNCTION FUN_00402330 @ 00402330

undefined4 * __fastcall FUN_00402330(undefined4 *param_1)

{
  *(undefined8 *)(param_1 + 1) = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}



// FUNCTION FUN_00402350 @ 00402350

undefined4 * __thiscall FUN_00402350(undefined4 *param_1,int param_2)

{
  *param_1 = std::exception::vftable;
  *(undefined8 *)(param_1 + 1) = 0;
  ___std_exception_copy(param_2 + 4,param_1 + 1);
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}



// FUNCTION FUN_00402390 @ 00402390

undefined4 * __thiscall FUN_00402390(undefined4 *param_1,int param_2)

{
  *param_1 = std::exception::vftable;
  *(undefined8 *)(param_1 + 1) = 0;
  ___std_exception_copy(param_2 + 4,param_1 + 1);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



// FUNCTION FUN_004023d0 @ 004023d0

void FUN_004023d0(void)

{
  undefined4 extraout_ECX;
  
  FUN_00402330();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(extraout_ECX,&DAT_005badd4);
}



// FUNCTION FUN_004023f0 @ 004023f0

void FUN_004023f0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_005432f9("string too long");
}



// FUNCTION FUN_00402400 @ 00402400

uint __fastcall FUN_00402400(uint param_1)

{
  if ((int)param_1 < 1) {
    return param_1;
  }
  return param_1 & 0xffff | 0x80070000;
}



// FUNCTION FUN_00402410 @ 00402410

DWORD FUN_00402410(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// FUNCTION FUN_00402430 @ 00402430

undefined4 * __thiscall FUN_00402430(undefined4 *param_1,int param_2)

{
  *param_1 = std::exception::vftable;
  *(undefined8 *)(param_1 + 1) = 0;
  ___std_exception_copy(param_2 + 4,param_1 + 1);
  return param_1;
}



// FUNCTION FUN_00402460 @ 00402460

char * __fastcall FUN_00402460(int param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    pcVar1 = *(char **)(param_1 + 4);
  }
  return pcVar1;
}



// FUNCTION FUN_00402470 @ 00402470

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * __thiscall FUN_00402470(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  local_10 = param_2;
  local_c = 1;
  *param_1 = std::exception::vftable;
  *(undefined8 *)(param_1 + 1) = 0;
  ___std_exception_copy(&local_10,param_1 + 1);
  return param_1;
}



// FUNCTION AtlMultiply<> @ 004024c0

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlMultiply<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 AtlMultiply<>(undefined4 *param_1,uint param_2,uint param_3)

{
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) != 0) {
    return 0x80070216;
  }
  *param_1 = (int)((ulonglong)param_2 * (ulonglong)param_3);
  return 0;
}



// FUNCTION FUN_004024f0 @ 004024f0

void FUN_004024f0(int param_1)

{
  code *pcVar1;
  
  if (param_1 == -0x7ff8fff2) {
                    /* WARNING: Subroutine does not return */
    FUN_00405d92();
  }
  FUN_00405566(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// FUNCTION FUN_00402510 @ 00402510

uint __fastcall FUN_00402510(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  uint uVar2;
  
  BVar1 = InitializeCriticalSectionEx(param_1,0,0);
  if (BVar1 == 0) {
    uVar2 = GetLastError();
    if (0 < (int)uVar2) {
      return uVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// FUNCTION FUN_00402540 @ 00402540

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00402540(void)

{
  BOOL BVar1;
  
  if ((*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_005c8ab0) &&
     (FUN_0054202f(&DAT_005c8ab0), DAT_005c8ab0 == -1)) {
    DAT_005c8a8c = 0;
    _DAT_005c8aa8 = 0;
    _DAT_005c8aac = 0;
    BVar1 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)&DAT_005c8a90,0,0);
    if ((BVar1 == 0) && (_DAT_005c8aac = GetLastError(), 0 < (int)_DAT_005c8aac)) {
      _DAT_005c8aac = _DAT_005c8aac & 0xffff | 0x80070000;
    }
    _atexit((_func_4879 *)&LAB_0056e500);
    FUN_00541fe5(&DAT_005c8ab0);
  }
  return &DAT_005c8a8c;
}



// FUNCTION FUN_004025d0 @ 004025d0

undefined4 * FUN_004025d0(void)

{
  if (*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_005c8a88) {
    FUN_0054202f(&DAT_005c8a88);
    if (DAT_005c8a88 == -1) {
      DAT_005c8ab4 = 0;
      DAT_005c8ab8 = 0;
      uRam005c8abc = 0;
      uRam005c8ac0 = 0;
      _atexit((_func_4879 *)&LAB_0056e4d0);
      FUN_00541fe5(&DAT_005c8a88);
    }
  }
  return &DAT_005c8ab4;
}



// FUNCTION FUN_00402630 @ 00402630

void __fastcall FUN_00402630(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if (*param_1 != 0) {
    GdiplusShutdown(*param_1);
  }
  *param_1 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return;
}



// FUNCTION AtlAdd<> @ 00402660

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlAdd<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlAdd<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2015 Release */

undefined4 AtlAdd<>(int *param_1,uint param_2,uint param_3)

{
  if (~param_2 < param_3) {
    return 0x80070216;
  }
  *param_1 = param_2 + param_3;
  return 0;
}



// FUNCTION AtlAdd<int> @ 00402690

/* Library Function - Single Match
    long __cdecl ATL::AtlAdd<int>(int *,int,int)
   
   Library: Visual Studio 2015 Release */

long __cdecl ATL::AtlAdd<int>(int *param_1,int param_2,int param_3)

{
  if (0x7fffffff - param_2 < param_3) {
    return -0x7ff8fdea;
  }
  *param_1 = param_2 + param_3;
  return 0;
}



// FUNCTION FUN_004026c0 @ 004026c0

undefined4 FUN_004026c0(void)

{
  return 0x5a2d9c;
}



// FUNCTION FUN_004026d0 @ 004026d0

undefined4 __thiscall FUN_004026d0(undefined4 param_1,uint param_2)

{
  FUN_00406776();
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      thunk_FUN_005473a0(param_1);
      return param_1;
    }
    guard_check_icall(param_1,0xcc);
  }
  return param_1;
}



// FUNCTION FUN_00402710 @ 00402710

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_00402710(int param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 local_29c [640];
  INITCOMMONCONTROLSEX local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055fffd;
  local_10 = ExceptionList;
  uVar1 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c.dwSize = 8;
  local_1c.dwICC = 0xff;
  local_14 = uVar1;
  InitCommonControlsEx(&local_1c);
  FUN_00406f24(uVar1);
  puVar2 = (undefined8 *)FUN_0040526e(0xc);
  local_8 = 0;
  if (puVar2 == (undefined8 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 1) = 0;
    piVar3 = (int *)FUN_00407d48();
  }
  local_8 = 0xffffffff;
  FUN_0041071e(&PTR_s_CMFCVisualManagerWindows_00570b2c);
  SetRegistryKey(L"Local AppWizard-Generated Applications");
  uVar4 = 0x280;
  _memset(local_29c,0,0x280);
  FUN_00403740(uVar4);
  local_8 = 1;
  *(undefined1 **)(param_1 + 0x20) = local_29c;
  FUN_0041472a();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(1);
  }
  ControlBarCleanUp();
  FUN_00402830();
  ExceptionList = local_10;
  return 0;
}



// FUNCTION FUN_00402830 @ 00402830

void __fastcall FUN_00402830(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00560030;
  local_10 = ExceptionList;
  uVar3 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  Concurrency::details::ExternalContextBase::~ExternalContextBase
            ((ExternalContextBase *)(param_1 + 0x200));
  FUN_00402960(uVar3);
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0x1e0) + -0x10);
  LOCK();
  piVar1 = (int *)(*(int *)(param_1 + 0x1e0) + -4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(*(int *)*puVar4 + 4))(puVar4);
  }
  Concurrency::details::ExternalContextBase::~ExternalContextBase
            ((ExternalContextBase *)(param_1 + 0x160));
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0x15c) + -0x10);
  LOCK();
  piVar1 = (int *)(*(int *)(param_1 + 0x15c) + -4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(*(int *)*puVar4 + 4))(puVar4);
  }
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0x158) + -0x10);
  LOCK();
  piVar1 = (int *)(*(int *)(param_1 + 0x158) + -4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(*(int *)*puVar4 + 4))(puVar4);
  }
  Concurrency::details::ExternalContextBase::~ExternalContextBase
            ((ExternalContextBase *)(param_1 + 0xd8));
  FUN_00419ae0();
  *(undefined ***)(param_1 + 0xb4) = CBrush::vftable;
  FUN_00402b50();
  FUN_0041419a();
  ExceptionList = local_10;
  return;
}



// FUNCTION ~CDialogEx @ 00402920

/* Library Function - Single Match
    public: virtual __thiscall CDialogEx::~CDialogEx(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CDialogEx::~CDialogEx(CDialogEx *this)

{
  FUN_00419ae0();
  *(undefined ***)(this + 0xb4) = CBrush::vftable;
  FUN_00402b50();
  FUN_0041419a();
  return;
}



// FUNCTION thunk_FUN_00402960 @ 00402950

void __fastcall thunk_FUN_00402960(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = (int *)*param_1;
  if (piVar5 != (int *)0x0) {
    piVar1 = (int *)param_1[1];
    for (; piVar5 != piVar1; piVar5 = piVar5 + 1) {
      iVar2 = *piVar5;
      if (iVar2 != 0) {
        FUN_00401c60();
        FUN_00541f12(iVar2,0x94);
      }
    }
    iVar2 = *param_1;
    uVar4 = param_1[2] - iVar2 & 0xfffffffc;
    iVar3 = iVar2;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar2 + -4);
      uVar4 = uVar4 + 0x23;
      if (0x1f < (iVar2 - iVar3) - 4U) {
                    /* WARNING: Subroutine does not return */
        FUN_0054734f();
      }
    }
    FUN_00541f12(iVar3,uVar4);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}



// FUNCTION FUN_00402960 @ 00402960

void __fastcall FUN_00402960(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = (int *)*param_1;
  if (piVar5 != (int *)0x0) {
    piVar1 = (int *)param_1[1];
    for (; piVar5 != piVar1; piVar5 = piVar5 + 1) {
      iVar2 = *piVar5;
      if (iVar2 != 0) {
        FUN_00401c60();
        FUN_00541f12(iVar2,0x94);
      }
    }
    iVar2 = *param_1;
    uVar4 = param_1[2] - iVar2 & 0xfffffffc;
    iVar3 = iVar2;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar2 + -4);
      uVar4 = uVar4 + 0x23;
      if (0x1f < (iVar2 - iVar3) - 4U) {
                    /* WARNING: Subroutine does not return */
        FUN_0054734f();
      }
    }
    FUN_00541f12(iVar3,uVar4);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}



// FUNCTION FUN_00402a00 @ 00402a00

void __fastcall FUN_00402a00(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_00401c60();
    FUN_00541f12(iVar1,0x94);
  }
  return;
}



// FUNCTION FUN_00402a20 @ 00402a20

undefined4 FUN_00402a20(void)

{
  return 5000;
}



// FUNCTION FUN_00402a30 @ 00402a30

undefined4 FUN_00402a30(void)

{
  return 0;
}



// FUNCTION FUN_00402a40 @ 00402a40

uint __fastcall FUN_00402a40(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 0x20;
}



// FUNCTION FUN_00402a50 @ 00402a50

uint __fastcall FUN_00402a50(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 0x10;
}



// FUNCTION FUN_00402a60 @ 00402a60

uint __fastcall FUN_00402a60(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 8;
}



// FUNCTION FUN_00402a70 @ 00402a70

uint __fastcall FUN_00402a70(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 4;
}



// FUNCTION FUN_00402a80 @ 00402a80

uint __fastcall FUN_00402a80(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 2;
}



// FUNCTION FUN_00402a90 @ 00402a90

uint __fastcall FUN_00402a90(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 1;
}



// FUNCTION FUN_00402aa0 @ 00402aa0

undefined4 * __thiscall FUN_00402aa0(undefined4 *param_1,uint param_2)

{
  *param_1 = CBrush::vftable;
  FUN_00402b50();
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      thunk_FUN_005473a0(param_1);
      return param_1;
    }
    guard_check_icall(param_1,8);
  }
  return param_1;
}



// FUNCTION FUN_00402ae0 @ 00402ae0

undefined4 __thiscall FUN_00402ae0(undefined4 param_1,uint param_2)

{
  FUN_00402b50();
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      thunk_FUN_005473a0(param_1);
      return param_1;
    }
    guard_check_icall(param_1,8);
  }
  return param_1;
}



// FUNCTION FUN_00402b20 @ 00402b20

void FUN_00402b20(void)

{
  return;
}



// FUNCTION FUN_00402b30 @ 00402b30

void FUN_00402b30(undefined4 param_1,undefined4 param_2)

{
  FUN_00403490(param_2,&stack0x0000000c);
  return;
}



// FUNCTION FUN_00402b50 @ 00402b50

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_00402b50(CGdiObject *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00560060;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = CGdiObject::vftable;
  local_8 = 0;
  CGdiObject::DeleteObject(param_1);
  ExceptionList = local_10;
  return;
}



// FUNCTION Catch@00402baf @ 00402baf

undefined4 Catch_00402baf(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x418) = 0;
  FUN_004036a0();
  piVar1 = *(int **)(unaff_EBP + -0x41c);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  iVar2 = (**(code **)(*piVar1 + 0xc))(unaff_EBP + -0x414,0x200,0);
  if (iVar2 == 0) {
    FUN_00402b30(unaff_EBP + -0x418,L"%Ts (%Ts:%d)",L"Exception thrown in destructor",
                 L"C:\\Program Files\\Microsoft Visual Studio\\2022\\Enterprise\\VC\\Tools\\MSVC\\14.36.32532\\atlmfc\\include\\afxwin1.inl"
                 ,0x4d);
  }
  else {
    FUN_00402b30(unaff_EBP + -0x418,L"%Ts (%Ts:%d)\n%Ts",L"Exception thrown in destructor",
                 L"C:\\Program Files\\Microsoft Visual Studio\\2022\\Enterprise\\VC\\Tools\\MSVC\\14.36.32532\\atlmfc\\include\\afxwin1.inl"
                 ,0x4d,unaff_EBP + -0x414);
  }
  FUN_00418240(*(undefined4 *)(unaff_EBP + -0x418),0,0);
  FUN_00403630();
  (**(code **)(*piVar1 + 4))(1);
  return 0x402b93;
}



// FUNCTION FUN_00402c60 @ 00402c60

void __fastcall FUN_00402c60(undefined4 *param_1)

{
  *param_1 = CBrush::vftable;
  FUN_00402b50();
  return;
}



// FUNCTION FUN_00402c70 @ 00402c70

void FUN_00402c70(undefined4 param_1)

{
  FUN_0040526e(param_1);
  return;
}



// FUNCTION FUN_00402c90 @ 00402c90

void FUN_00402c90(undefined4 param_1)

{
  thunk_FUN_005473a0(param_1);
  return;
}



// FUNCTION FUN_00402cb0 @ 00402cb0

ushort * FUN_00402cb0(HMODULE param_1,uint param_2)

{
  ushort *puVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  ushort *puVar2;
  DWORD DVar3;
  
  hResInfo = FindResourceW(param_1,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if (hResInfo == (HRSRC)0x0) {
    return (ushort *)0x0;
  }
  hResData = LoadResource(param_1,hResInfo);
  if ((hResData != (HGLOBAL)0x0) && (puVar2 = LockResource(hResData), puVar2 != (ushort *)0x0)) {
    DVar3 = SizeofResource(param_1,hResInfo);
    puVar1 = (ushort *)((int)puVar2 + DVar3);
    for (param_2 = param_2 & 0xf; param_2 != 0; param_2 = param_2 - 1) {
      if (puVar1 <= puVar2) {
        return (ushort *)0x0;
      }
      puVar2 = puVar2 + *puVar2 + 1;
    }
    if (puVar2 < puVar1) {
      if (*puVar2 == 0) {
        puVar2 = (ushort *)0x0;
      }
      return puVar2;
    }
  }
  return (ushort *)0x0;
}



// FUNCTION FUN_00402d40 @ 00402d40

undefined4 FUN_00402d40(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    return param_1;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_00405d78();
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_00405d92();
  }
}



// FUNCTION FUN_00402dd0 @ 00402dd0

undefined4 __thiscall FUN_00402dd0(int *param_1,uint param_2)

{
  ushort *puVar1;
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL hResData;
  ushort *puVar2;
  DWORD DVar3;
  errno_t eVar4;
  uint _N1;
  
  hModule = (HMODULE)FUN_0040649c(param_2);
  if ((((hModule != (HMODULE)0x0) &&
       (hResInfo = FindResourceW(hModule,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6),
       hResInfo != (HRSRC)0x0)) &&
      (hResData = LoadResource(hModule,hResInfo), hResData != (HGLOBAL)0x0)) &&
     (puVar2 = LockResource(hResData), puVar2 != (ushort *)0x0)) {
    DVar3 = SizeofResource(hModule,hResInfo);
    puVar1 = (ushort *)((int)puVar2 + DVar3);
    for (param_2 = param_2 & 0xf; param_2 != 0; param_2 = param_2 - 1) {
      if (puVar1 <= puVar2) {
        return 0;
      }
      puVar2 = puVar2 + *puVar2 + 1;
    }
    if ((puVar2 < puVar1) && (*puVar2 != 0)) {
      _N1 = (uint)*puVar2;
      if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - _N1) < 0) {
        FUN_004033a0(_N1);
      }
      eVar4 = _wmemcpy_s((wchar_t *)*param_1,_N1,(wchar_t *)(puVar2 + 1),(uint)*puVar2);
      switch(eVar4) {
      case 0:
      case 0x50:
        goto switchD_00402e9b_caseD_0;
      default:
                    /* WARNING: Subroutine does not return */
        FUN_00405d78();
      case 0xc:
                    /* WARNING: Subroutine does not return */
        FUN_00405d92();
      }
    }
  }
  return 0;
switchD_00402e9b_caseD_0:
  if ((int)_N1 <= *(int *)(*param_1 + -8)) {
    *(uint *)(*param_1 + -0xc) = _N1;
    *(undefined2 *)(*param_1 + _N1 * 2) = 0;
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80070057);
}



// FUNCTION FUN_00402f50 @ 00402f50

void __fastcall FUN_00402f50(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *param_1;
  puVar1 = (undefined4 *)(iVar4 + -0x10);
  piVar3 = (int *)*puVar1;
  if (*(int *)(iVar4 + -0xc) != 0) {
    piVar2 = (int *)(iVar4 + -4);
    if (*(int *)(iVar4 + -4) < 0) {
      if (-1 < *(int *)(iVar4 + -8)) {
        *(undefined4 *)(iVar4 + -0xc) = 0;
        *(undefined2 *)*param_1 = 0;
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_004024f0(0x80070057);
    }
    LOCK();
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 == 1 || iVar4 + -1 < 0) {
      (**(code **)(*(int *)*puVar1 + 4))(puVar1);
    }
    iVar4 = (**(code **)(*piVar3 + 0xc))();
    *param_1 = iVar4 + 0x10;
  }
  return;
}



// FUNCTION FUN_00402fb0 @ 00402fb0

void FUN_00402fb0(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = param_4 * 2;
  if (uVar1 != 0) {
    if (param_1 == 0) {
      puVar2 = (undefined4 *)FUN_00549bed();
      *puVar2 = 0x16;
      FUN_0054733f();
      return;
    }
    if (param_3 == 0) {
      puVar2 = (undefined4 *)FUN_00549bed();
      *puVar2 = 0x16;
      FUN_0054733f();
      return;
    }
    if ((uint)(param_2 * 2) < uVar1) {
      puVar2 = (undefined4 *)FUN_00549bed();
      *puVar2 = 0x22;
      FUN_0054733f();
      return;
    }
    FUN_00543940(param_1,param_3,uVar1);
  }
  return;
}



// FUNCTION FUN_00403020 @ 00403020

void __thiscall FUN_00403020(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  void *pvVar2;
  int *piVar3;
  uint uVar4;
  void *_Dst;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  if (param_3 == 0) {
    iVar6 = *param_1;
    puVar7 = (undefined4 *)(iVar6 + -0x10);
    piVar3 = (int *)*puVar7;
    if (*(int *)(iVar6 + -0xc) != 0) {
      piVar1 = (int *)(iVar6 + -4);
      if (-1 < *(int *)(iVar6 + -4)) {
        LOCK();
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar6 == 1 || iVar6 + -1 < 0) {
          (**(code **)(*(int *)*puVar7 + 4))(puVar7);
        }
        iVar6 = (**(code **)(*piVar3 + 0xc))();
        *param_1 = iVar6 + 0x10;
        return;
      }
      if (*(int *)(iVar6 + -8) < 0) goto LAB_00403178;
      *(undefined4 *)(iVar6 + -0xc) = 0;
      *(undefined2 *)*param_1 = 0;
    }
    return;
  }
  if (param_2 == 0) goto LAB_00403178;
  iVar6 = *param_1;
  uVar4 = *(uint *)(iVar6 + -0xc);
  uVar8 = param_2 - iVar6 >> 1;
  if (param_3 < 0) goto LAB_00403178;
  if ((int)(1U - *(int *)(iVar6 + -4) | *(int *)(iVar6 + -8) - param_3) < 0) {
    FUN_004033a0(param_3);
  }
  _Dst = (void *)*param_1;
  uVar5 = param_3 * 2;
  if (uVar4 < uVar8) {
    uVar4 = *(int *)((int)_Dst + -8) * 2;
    if (uVar5 != 0) {
      if (_Dst == (void *)0x0) {
        puVar7 = (undefined4 *)FUN_00549bed();
        *puVar7 = 0x16;
      }
      else {
        if (uVar5 <= uVar4) {
          FUN_00543940(_Dst,param_2,uVar5);
          goto LAB_0040315d;
        }
        _memset(_Dst,0,uVar4);
LAB_0040314d:
        puVar7 = (undefined4 *)FUN_00549bed();
        *puVar7 = 0x22;
      }
      goto LAB_00403158;
    }
  }
  else {
    pvVar2 = (void *)((int)_Dst + uVar8 * 2);
    if (uVar5 != 0) {
      if (_Dst == (void *)0x0) {
        puVar7 = (undefined4 *)FUN_00549bed();
        *puVar7 = 0x16;
      }
      else {
        if (pvVar2 != (void *)0x0) {
          if ((uint)(*(int *)((int)_Dst + -8) * 2) < uVar5) goto LAB_0040314d;
          FUN_00543940(_Dst,pvVar2,uVar5);
          goto LAB_0040315d;
        }
        puVar7 = (undefined4 *)FUN_00549bed();
        *puVar7 = 0x16;
      }
LAB_00403158:
      FUN_0054733f();
    }
  }
LAB_0040315d:
  if (param_3 <= *(int *)(*param_1 + -8)) {
    *(int *)(*param_1 + -0xc) = param_3;
    *(undefined2 *)(uVar5 + *param_1) = 0;
    return;
  }
LAB_00403178:
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80070057);
}



// FUNCTION FUN_00403190 @ 00403190

undefined4 __thiscall FUN_00403190(undefined4 param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  
  if (param_2 == (short *)0x0) {
    FUN_00403020(0,0);
    return param_1;
  }
  psVar2 = param_2;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00403020(param_2,(int)psVar2 - (int)(param_2 + 1) >> 1);
  return param_1;
}



// FUNCTION FUN_004031e0 @ 004031e0

int * __thiscall FUN_004031e0(int *param_1,short *param_2,int *param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0056009d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_004024f0(0x80004005,DAT_005bffe4 ^ (uint)&stack0xfffffffc);
  }
  iVar2 = (**(code **)(*param_3 + 0xc))();
  *param_1 = iVar2 + 0x10;
  local_8 = 0;
  if (param_2 == (short *)0x0) {
    iVar2 = 0;
  }
  else {
    if (((uint)param_2 & 0xffff0000) == 0) {
      FUN_00402dd0((uint)param_2 & 0xffff);
      ExceptionList = local_10;
      return param_1;
    }
    psVar3 = param_2;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    iVar2 = (int)psVar3 - (int)(param_2 + 1) >> 1;
  }
  FUN_00403020(param_2,iVar2);
  ExceptionList = local_10;
  return param_1;
}



// FUNCTION FUN_00403280 @ 00403280

void __fastcall FUN_00403280(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(int **)(*param_1 + -0x10) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(*param_1 + -0x10) + 0x10))();
    if (iVar1 != 0) {
      return;
    }
  }
  piVar2 = (int *)FUN_004062c5();
                    /* WARNING: Could not recover jumptable at 0x0040329b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x10))();
  return;
}



// FUNCTION FUN_004032a0 @ 004032a0

void __thiscall FUN_004032a0(int *param_1,int param_2)

{
  int *piVar1;
  size_t _Size;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  void *_Dst;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + -0xc);
  puVar4 = (undefined4 *)(**(code **)(**(int **)(iVar2 + -0x10) + 0x10))();
  iVar5 = (**(code **)*puVar4)(param_2,2);
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00403350();
  }
  if (iVar3 < param_2) {
    param_2 = iVar3;
  }
  _Size = param_2 * 2 + 2;
  _Dst = (void *)(iVar5 + 0x10);
  if (_Size != 0) {
    if (_Dst != (void *)0x0) {
      if (iVar2 != 0) {
        FUN_00543940(_Dst,iVar2);
        goto LAB_0040331c;
      }
      _memset(_Dst,0,_Size);
    }
    puVar4 = (undefined4 *)FUN_00549bed();
    *puVar4 = 0x16;
    FUN_0054733f();
  }
LAB_0040331c:
  *(int *)(iVar5 + 4) = iVar3;
  LOCK();
  piVar1 = (int *)(iVar2 + -4);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)(iVar2 + -0x10) + 4))((undefined4 *)(iVar2 + -0x10));
  }
  *param_1 = (int)_Dst;
  return;
}



// FUNCTION FUN_00403350 @ 00403350

void FUN_00403350(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x8007000e);
}



// FUNCTION FUN_00403360 @ 00403360

void __thiscall FUN_00403360(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*param_1 + -0x10);
  if ((*(int *)(*param_1 + -8) < param_2) && (0 < param_2)) {
    iVar1 = (**(code **)(*(int *)*puVar2 + 8))(puVar2,param_2,2);
    if (iVar1 != 0) {
      *param_1 = iVar1 + 0x10;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00403350();
}



// FUNCTION FUN_004033a0 @ 004033a0

void __thiscall FUN_004033a0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (param_2 < *(int *)(iVar1 + -0xc)) {
    param_2 = *(int *)(iVar1 + -0xc);
  }
  if (1 < *(int *)(iVar1 + -4)) {
    FUN_004032a0(param_2);
    return;
  }
  iVar1 = *(int *)(iVar1 + -8);
  if (iVar1 < param_2) {
    if (iVar1 < 0x40000001) {
      iVar2 = iVar1 / 2;
    }
    else {
      iVar2 = 0x100000;
    }
    if (param_2 <= iVar2 + iVar1) {
      param_2 = iVar2 + iVar1;
    }
    FUN_00403360(param_2);
  }
  return;
}



// FUNCTION FUN_00403400 @ 00403400

int __thiscall FUN_00403400(int *param_1,int param_2)

{
  if (-1 < param_2) {
    if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - param_2) < 0) {
      FUN_004033a0(param_2);
    }
    return *param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80070057);
}



// FUNCTION FUN_00403440 @ 00403440

undefined * FUN_00403440(void)

{
  return &DAT_005c8a80;
}



// FUNCTION FUN_00403450 @ 00403450

undefined4 __fastcall FUN_00403450(undefined4 *param_1)

{
  return *param_1;
}



// FUNCTION FUN_00403460 @ 00403460

void __thiscall FUN_00403460(int *param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 <= *(int *)(*param_1 + -8))) {
    *(int *)(*param_1 + -0xc) = param_2;
    *(undefined2 *)(*param_1 + param_2 * 2) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80070057);
}



// FUNCTION FUN_00403490 @ 00403490

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00403490(int *param_1,short *param_2,undefined4 param_3)

{
  short sVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  short *psVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005600d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 == (short *)0x0) goto LAB_00403617;
  puVar2 = (uint *)FUN_00403440(DAT_005bffe4 ^ (uint)&stack0xfffffffc);
  iVar3 = FUN_00549ace(*puVar2 | 6,puVar2[1],0,0,param_2,0,param_3);
  if (iVar3 < 0) {
    iVar3 = -1;
  }
  if (iVar3 < 0) goto LAB_0040360d;
  if (*(int **)(*param_1 + -0x10) == (int *)0x0) {
LAB_00403515:
    piVar4 = (int *)FUN_004062c5();
    piVar4 = (int *)(**(code **)(*piVar4 + 0x10))();
    if (piVar4 == (int *)0x0) {
LAB_0040360d:
                    /* WARNING: Subroutine does not return */
      FUN_004024f0(0x80004005);
    }
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(*param_1 + -0x10) + 0x10))();
    if (piVar4 == (int *)0x0) goto LAB_00403515;
  }
  puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0xc))();
  local_8 = 0;
  if (((uint)param_2 & 0xffff0000) == 0) {
    FUN_00402dd0((uint)param_2 & 0xffff);
  }
  else {
    psVar6 = param_2;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00403020(param_2,(int)psVar6 - (int)(param_2 + 1) >> 1);
  }
  local_8 = 1;
  if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - iVar3) < 0) {
    FUN_004033a0(iVar3);
  }
  FUN_00549b0f(*puVar2 | 4,puVar2[1],*param_1,iVar3 + 1,puVar5 + 4,0,param_3);
  if (iVar3 <= *(int *)(*param_1 + -8)) {
    *(int *)(*param_1 + -0xc) = iVar3;
    local_8 = 0xffffffff;
    *(undefined2 *)(*param_1 + iVar3 * 2) = 0;
    LOCK();
    piVar4 = puVar5 + 3;
    iVar3 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      (**(code **)(*(int *)*puVar5 + 4))(puVar5);
    }
    ExceptionList = local_10;
    return;
  }
LAB_00403617:
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80070057);
}



// FUNCTION FUN_00403630 @ 00403630

void __fastcall FUN_00403630(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(*param_1 + -0x10);
  LOCK();
  piVar1 = (int *)(*param_1 + -4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(*(int *)*puVar3 + 4))(puVar3);
  }
  return;
}



// FUNCTION FUN_00403650 @ 00403650

int * __thiscall FUN_00403650(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0xc))();
    *param_1 = iVar1 + 0x10;
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80004005);
}



// FUNCTION FUN_00403680 @ 00403680

void __fastcall FUN_00403680(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = param_1 + 3;
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(*(int *)*param_1 + 4))(param_1);
  }
  return;
}



// FUNCTION FUN_004036a0 @ 004036a0

int * __fastcall FUN_004036a0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_004062c5();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    *param_1 = iVar2 + 0x10;
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80004005);
}



// FUNCTION FUN_004036d0 @ 004036d0

int __thiscall FUN_004036d0(int param_1,uint param_2)

{
  FUN_00419ae0();
  *(undefined ***)(param_1 + 0xb4) = CBrush::vftable;
  FUN_00402b50();
  FUN_0041419a();
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      thunk_FUN_005473a0(param_1);
      return param_1;
    }
    guard_check_icall(param_1,0xd0);
  }
  return param_1;
}



// FUNCTION FUN_00403730 @ 00403730

undefined4 FUN_00403730(void)

{
  return 0x5a317c;
}



// FUNCTION FUN_00403740 @ 00403740

/* WARNING: Removing unreachable block (ram,0x004037dc) */
/* WARNING: Removing unreachable block (ram,0x00403822) */
/* WARNING: Removing unreachable block (ram,0x00403882) */

CDialogEx * __fastcall FUN_00403740(CDialogEx *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  HICON pHVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00560187;
  local_10 = ExceptionList;
  uVar1 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  CDialogEx::CDialogEx(param_1,0x66,(CWnd *)0x0);
  local_8 = 0;
  *(undefined ***)param_1 = CupdaterDlg::vftable;
  FUN_0041beb5(uVar1);
  *(undefined ***)(param_1 + 0xd8) = CComboBox::vftable;
  local_8._0_1_ = 1;
  piVar2 = (int *)FUN_004062c5();
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    *(int *)(param_1 + 0x158) = iVar3 + 0x10;
    local_8._0_1_ = 2;
    FUN_00403020(&DAT_005a2fe8,0);
    local_8._0_1_ = 3;
    piVar2 = (int *)FUN_004062c5();
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0xc))();
      *(int *)(param_1 + 0x15c) = iVar3 + 0x10;
      local_8._0_1_ = 4;
      FUN_00403020(&DAT_005a2fe8,0);
      local_8._0_1_ = 5;
      FUN_0041beb5();
      *(undefined ***)(param_1 + 0x160) = CProgressCtrl::vftable;
      local_8._0_1_ = 6;
      piVar2 = (int *)FUN_004062c5();
      if (piVar2 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar2 + 0xc))();
        *(int *)(param_1 + 0x1e0) = iVar3 + 0x10;
        local_8._0_1_ = 7;
        FUN_00403020(&DAT_005a2fe8,0);
        *(undefined4 *)(param_1 + 0x1e4) = 0;
        *(undefined4 *)(param_1 + 0x1e8) = 0;
        *(undefined4 *)(param_1 + 0x1ec) = 0;
        local_8._0_1_ = 9;
        *(undefined4 *)(param_1 + 0x1f0) = 0;
        *(undefined4 *)(param_1 + 500) = 0;
        FUN_0041beb5();
        *(undefined ***)(param_1 + 0x200) = CButton::vftable;
        local_8 = CONCAT31(local_8._1_3_,10);
        FUN_0042350a();
        iVar3 = FUN_0042350a();
        pHVar4 = LoadIconW(*(HINSTANCE *)(iVar3 + 0xc),(LPCWSTR)0x80);
        *(HICON *)(param_1 + 0xd0) = pHVar4;
        ExceptionList = local_10;
        return param_1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80004005);
}



// FUNCTION FUN_00403930 @ 00403930

undefined4 __thiscall FUN_00403930(undefined4 param_1,uint param_2)

{
  FUN_00402830();
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      thunk_FUN_005473a0(param_1);
      return param_1;
    }
    guard_check_icall(param_1,0x280);
  }
  return param_1;
}



// FUNCTION FUN_00403970 @ 00403970

void __thiscall FUN_00403970(int param_1,undefined4 param_2)

{
  FUN_004235fb(param_2,1000,param_1 + 0xd8);
  DDX_Text(param_2,0x3ed,param_1 + 0x158);
  DDX_Text(param_2,0x3ee,param_1 + 0x15c);
  FUN_004235fb(param_2,0x3eb,param_1 + 0x160);
  FUN_004235fb(param_2,0x3ef,param_1 + 0x200);
  return;
}



// FUNCTION FUN_004039e0 @ 004039e0

undefined ** FUN_004039e0(void)

{
  return &PTR_FUN_005a2f4c;
}



// FUNCTION FUN_004039f0 @ 004039f0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_004039f0(int param_1)

{
  LPCWSTR pWVar1;
  LPCWSTR pWVar2;
  HMENU pHVar3;
  CMenu *pCVar4;
  int *piVar5;
  int iVar6;
  LPCWSTR local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005601c5;
  local_10 = ExceptionList;
  local_14 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00414bb7(local_14);
  pHVar3 = GetSystemMenu(*(HWND *)(param_1 + 0x20),0);
  pCVar4 = CMenu::FromHandle(pHVar3);
  if (pCVar4 != (CMenu *)0x0) {
    piVar5 = (int *)FUN_004062c5();
    if (piVar5 == (int *)0x0) goto LAB_00403b9e;
    iVar6 = (**(code **)(*piVar5 + 0xc))();
    local_18 = (LPCWSTR)(iVar6 + 0x10);
    local_8 = 0;
    FUN_00402dd0(0x65);
    pWVar2 = local_18;
    if (*(int *)(local_18 + -6) != 0) {
      AppendMenuW(*(HMENU *)(pCVar4 + 4),0x800,0,(LPCWSTR)0x0);
      AppendMenuW(*(HMENU *)(pCVar4 + 4),0,0x10,pWVar2);
    }
    local_8 = 0xffffffff;
    LOCK();
    pWVar1 = pWVar2 + -2;
    iVar6 = *(int *)pWVar1;
    *(int *)pWVar1 = *(int *)pWVar1 + -1;
    UNLOCK();
    if (iVar6 == 1 || iVar6 + -1 < 0) {
      (**(code **)(**(int **)(pWVar2 + -8) + 4))(pWVar2 + -8);
    }
  }
  SendMessageW(*(HWND *)(param_1 + 0x20),0x80,1,*(LPARAM *)(param_1 + 0xd0));
  SendMessageW(*(HWND *)(param_1 + 0x20),0x80,0,*(LPARAM *)(param_1 + 0xd0));
  FUN_004048c0(&DAT_005a2dd4);
  *(undefined1 *)(param_1 + 0x1fc) = 0;
  piVar5 = (int *)FUN_004062c5();
  if (piVar5 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar5 + 0xc))();
    local_18 = (LPCWSTR)(iVar6 + 0x10);
    local_8 = 1;
    FUN_00402b30(&local_18,L"%d.%d.%d",1,1,5);
    FUN_00404780(&local_18);
    FUN_00420d8c(0);
    FUN_00403dd0();
    Sleep(100);
    FUN_00403eb0();
    local_8 = 0xffffffff;
    LOCK();
    pWVar2 = local_18 + -2;
    iVar6 = *(int *)pWVar2;
    *(int *)pWVar2 = *(int *)pWVar2 + -1;
    UNLOCK();
    if (iVar6 == 1 || iVar6 + -1 < 0) {
      (**(code **)(**(int **)(local_18 + -8) + 4))(local_18 + -8);
    }
    ExceptionList = local_10;
    return 1;
  }
LAB_00403b9e:
                    /* WARNING: Subroutine does not return */
  FUN_004024f0(0x80004005);
}



// FUNCTION FUN_00403bb0 @ 00403bb0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00403bb0(uint param_1)

{
  undefined **local_e4 [45];
  undefined **local_30;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00560200;
  local_10 = ExceptionList;
  local_14 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 & 0xfff0) == 0x10) {
    _memset(local_e4,0,0xd0);
    CDialogEx::CDialogEx((CDialogEx *)local_e4,100,(CWnd *)0x0);
    local_e4[0] = CAboutDlg::vftable;
    local_8 = 0;
    FUN_0041472a();
    FUN_00419ae0();
    local_30 = CBrush::vftable;
    FUN_00402b50();
    FUN_0041419a();
  }
  else {
    FUN_0041dacb(local_14);
  }
  ExceptionList = local_10;
  return;
}



// FUNCTION FUN_00403c70 @ 00403c70

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_00403c70(CDialog *param_1)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_7c [4];
  tagRECT local_78;
  undefined1 local_68 [4];
  HDC local_64;
  uint local_c;
  
  local_c = DAT_005bffe4 ^ (uint)auStack_7c;
  BVar1 = IsIconic(*(HWND *)(param_1 + 0x20));
  if (BVar1 != 0) {
    _memset(local_68,0,0x54);
    FUN_004185d0(param_1);
    SendMessageW(*(HWND *)(param_1 + 0x20),0x27,(WPARAM)local_64,0);
    iVar2 = GetSystemMetrics(0xb);
    iVar3 = GetSystemMetrics(0xc);
    local_78.left = 0;
    local_78.top = 0;
    local_78.right = 0;
    local_78.bottom = 0;
    GetClientRect(*(HWND *)(param_1 + 0x20),&local_78);
    DrawIcon(local_64,(((local_78.right - local_78.left) - iVar2) + 1) / 2,
             (((local_78.bottom - local_78.top) - iVar3) + 1) / 2,*(HICON *)(param_1 + 0xd0));
    FUN_00418764();
    return;
  }
  CDialog::OnPaint(param_1);
  return;
}



// FUNCTION FUN_00403d60 @ 00403d60

undefined4 __fastcall FUN_00403d60(int param_1)

{
  return *(undefined4 *)(param_1 + 0xd0);
}



// FUNCTION FUN_00403d70 @ 00403d70

undefined4 __thiscall FUN_00403d70(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 7) {
    FUN_00403dd0();
    Sleep(100);
    FUN_00403eb0();
    if (*(char *)(param_1 + 0x1fc) == '\0') {
      uVar1 = (uint)(*(int *)(param_1 + 0x1f0) != 0);
      FUN_00422cae(0x3ef);
      FUN_00422c40(uVar1);
    }
  }
  return 1;
}



// FUNCTION FUN_00403dd0 @ 00403dd0

int __fastcall FUN_00403dd0(int param_1)

{
  int iVar1;
  int iVar2;
  
  SendMessageW(*(HWND *)(param_1 + 0xf8),0x14b,0,0);
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  iVar1 = FUN_00404db0();
  if (-1 < iVar1) {
    iVar1 = *(int *)(param_1 + 0x1e8);
    iVar2 = *(int *)(param_1 + 0x1e4);
    if ((iVar1 - iVar2 & 0xfffffffcU) == 0) {
      SendMessageW(*(HWND *)(param_1 + 0xf8),0x143,0,0x5a2dec);
      SendMessageW(*(HWND *)(param_1 + 0xf8),0x14e,0,0);
      return 1;
    }
    for (; iVar2 != iVar1; iVar2 = iVar2 + 4) {
      SendMessageW(*(HWND *)(param_1 + 0xf8),0x143,0,0x5a2dfc);
    }
    SendMessageW(*(HWND *)(param_1 + 0xf8),0x14e,0,0);
    *(undefined4 *)(param_1 + 0x1f0) = **(undefined4 **)(param_1 + 0x1e4);
    iVar1 = 0;
  }
  return iVar1;
}



// FUNCTION FUN_00403eb0 @ 00403eb0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_00403eb0(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 extraout_ECX;
  wchar_t *pwVar7;
  uint uStack_48;
  undefined8 local_28;
  int local_20;
  int local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00560255;
  local_10 = ExceptionList;
  uStack_48 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_18 = uStack_48;
  piVar3 = (int *)FUN_004062c5();
  if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_004024f0(0x80004005);
  }
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0xc))();
  local_8 = 0;
  if (*(int *)(param_1 + 0x1f0) == 0) {
    FUN_004048c0(&DAT_005a2dd4);
  }
  else {
    local_8 = 1;
    iVar6 = *(int *)(param_1 + 0x1f0);
    local_28 = 0;
    *(undefined4 *)(iVar6 + 0x90) = 0;
    FUN_00401fc0(&local_28,extraout_ECX);
    if (local_28._4_4_ != 0) {
      *(undefined4 *)(iVar6 + 0x90) = *(undefined4 *)((int)local_28 + 8);
    }
    if ((int)local_28 != 0) {
      thunk_FUN_005473a0((int)local_28);
    }
    piVar3 = (int *)FUN_004062c5();
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004024f0(0x80004005);
    }
    puVar5 = (undefined4 *)(**(code **)(*piVar3 + 0xc))();
    local_28 = CONCAT44(puVar5 + 4,(int)local_28);
    local_8._0_1_ = 2;
    piVar3 = (int *)FUN_004062c5();
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004024f0(0x80004005);
    }
    iVar6 = (**(code **)(*piVar3 + 0xc))();
    iVar6 = iVar6 + 0x10;
    local_8._0_1_ = 3;
    local_1c = iVar6;
    piVar3 = (int *)FUN_004062c5();
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004024f0(0x80004005);
    }
    local_20 = (**(code **)(*piVar3 + 0xc))();
    local_20 = local_20 + 0x10;
    local_8._0_1_ = 4;
    uVar2 = *(uint *)(*(int *)(param_1 + 0x1f0) + 0x90);
    if (uVar2 == 0) {
      FUN_004048c0(&DAT_005a2dd4);
    }
    else if (*(char *)(param_1 + 0x1fc) == '\0') {
      if ((uVar2 & 0xff000000) == 0) {
        pwVar7 = L"%d.%d.%d";
      }
      else {
        pwVar7 = L"%d.%d.%d BL";
      }
      FUN_00402b30(&local_1c,pwVar7,uVar2 >> 0x10 & 0xff,uVar2 >> 8 & 0xff,uVar2 & 0xff);
      FUN_00404780(&local_1c);
      iVar6 = local_1c;
    }
    FUN_00402b30(&local_20,L"%d.%d.%d",1,1,5);
    FUN_00404780(&local_20);
    FUN_00420d8c(0);
    local_8._0_1_ = 3;
    LOCK();
    piVar3 = (int *)(local_20 + -4);
    iVar1 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      (**(code **)(**(int **)(local_20 + -0x10) + 4))((undefined4 *)(local_20 + -0x10));
    }
    local_8._0_1_ = 2;
    LOCK();
    piVar3 = (int *)(iVar6 + -4);
    iVar1 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      (**(code **)(**(int **)(iVar6 + -0x10) + 4))((undefined4 *)(iVar6 + -0x10));
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    LOCK();
    piVar3 = puVar5 + 3;
    iVar6 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar6 == 1 || iVar6 + -1 < 0) {
      (**(code **)(*(int *)*puVar5 + 4))(puVar5);
    }
  }
  local_8 = 0xffffffff;
  LOCK();
  piVar3 = puVar4 + 3;
  iVar6 = *piVar3;
  *piVar3 = *piVar3 + -1;
  UNLOCK();
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    (**(code **)(*(int *)*puVar4 + 4))(puVar4);
  }
  ExceptionList = local_10;
  return;
}



// FUNCTION Catch@004040ca @ 004040ca

undefined * Catch_004040ca(void)

{
  return &DAT_004040d0;
}



// FUNCTION FUN_00404150 @ 00404150

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00404150(void)

{
  BOOL BVar1;
  int iVar2;
  tagMSG local_24;
  uint local_8;
  
  local_8 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  BVar1 = PeekMessageW(&local_24,(HWND)0x0,0,0,0);
  if (BVar1 != 0) {
    while( true ) {
      iVar2 = FUN_0042350a();
      iVar2 = (**(code **)(**(int **)(iVar2 + 4) + 0x5c))();
      if (iVar2 == 0) break;
      BVar1 = PeekMessageW(&local_24,(HWND)0x0,0,0,0);
      if (BVar1 == 0) {
        return;
      }
    }
    PostQuitMessage(0);
  }
  return;
}



// FUNCTION FUN_004041d0 @ 004041d0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004041d0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  BOOL BVar5;
  int iVar6;
  HRSRC hResInfo;
  DWORD DVar7;
  HGLOBAL hResData;
  LPVOID pvVar8;
  undefined4 *puVar9;
  WPARAM WVar10;
  undefined4 uVar11;
  uint uStack_70;
  int local_4c;
  tagMSG local_48;
  int local_2c;
  undefined4 *local_28;
  uint uStack_24;
  undefined8 *local_20;
  undefined4 *puStack_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005602ad;
  local_10 = ExceptionList;
  uStack_70 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_70;
  ExceptionList = &local_10;
  local_18 = uStack_70;
  piVar1 = (int *)FUN_004062c5();
  if (piVar1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_004024f0(0x80004005);
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  iVar2 = iVar2 + 0x10;
  uVar11 = 0;
  local_8 = 0;
  *(undefined1 *)(param_1 + 0x1fc) = 1;
  local_2c = iVar2;
  FUN_00422cae(0x3ef);
  FUN_00422c40(uVar11);
  FUN_00404150();
  puVar9 = (undefined4 *)(param_1 + 0x180);
  if (*(int *)(param_1 + 0x1f0) != 0) {
    SendMessageW((HWND)*puVar9,0x402,0,0);
    local_20 = (undefined8 *)0x0;
    puStack_1c = (undefined4 *)0x9;
    puVar3 = (undefined8 *)FUN_00405265(9);
    _local_20 = CONCAT44(puStack_1c,puVar3);
    *puVar3 = 0;
    *(undefined1 *)(puVar3 + 1) = 0;
    local_8._0_1_ = 1;
    *(undefined4 *)puVar3 = 0xadabff55;
    *(undefined2 *)((int)puVar3 + 4) = 0xbeba;
    FUN_00402090(3,&local_20);
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_20 != (undefined8 *)0x0) {
      thunk_FUN_005473a0(local_20);
    }
    WVar10 = 1;
    do {
      Sleep(0x96);
      SendMessageW((HWND)*puVar9,0x402,WVar10,0);
      FUN_00404150();
      iVar2 = local_2c;
      WVar10 = WVar10 + 1;
    } while ((int)WVar10 < 8);
    local_4c = 0;
    *(undefined4 *)(param_1 + 0x1f0) = 0;
    do {
      Sleep(300);
      FUN_00403dd0();
      if (*(int *)(param_1 + 0x1f0) != 0) {
        Sleep(1000);
        break;
      }
      FUN_00404150();
      local_4c = local_4c + 1;
    } while (local_4c < 10);
    SendMessageW((HWND)*puVar9,0x402,10,0);
    if (*(int *)(param_1 + 0x1f0) == 0) {
      FUN_0041e91f(L"Fail to Find Handbrake!",L"Error",0x10);
      FUN_00404707();
      return;
    }
    local_8._0_1_ = 2;
    local_20 = (undefined8 *)0x0;
    puStack_1c = (undefined4 *)0x20;
    puVar4 = (undefined4 *)FUN_00405265(0x20);
    _local_20 = CONCAT44(puStack_1c,puVar4);
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    local_8._0_1_ = 3;
    *(undefined1 *)puVar4 = 2;
    FUN_00402090(0xf1,&local_20);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_20 != (undefined8 *)0x0) {
      thunk_FUN_005473a0(local_20);
    }
    for (WVar10 = 10; (int)WVar10 < 0x15; WVar10 = WVar10 + 1) {
      SendMessageW((HWND)*puVar9,0x402,WVar10,0);
      Sleep(100);
      do {
        BVar5 = PeekMessageW(&local_48,(HWND)0x0,0,0,0);
        if (BVar5 == 0) goto LAB_00404450;
        iVar6 = FUN_0042350a();
        iVar6 = (**(code **)(**(int **)(iVar6 + 4) + 0x5c))();
      } while (iVar6 != 0);
      PostQuitMessage(0);
LAB_00404450:
    }
    FUN_00403eb0();
    Sleep(1);
    hResInfo = FindResourceW((HMODULE)0x0,L"IDR_APP_FILE",L"TEXTFILE");
    if (hResInfo != (HRSRC)0x0) {
      DVar7 = SizeofResource((HMODULE)0x0,hResInfo);
      *(DWORD *)(param_1 + 0x1f8) = DVar7;
      hResData = LoadResource((HMODULE)0x0,hResInfo);
      pvVar8 = LockResource(hResData);
      *(LPVOID *)(param_1 + 500) = pvVar8;
    }
    local_4c = 0;
    _local_28 = CONCAT44(*(int *)(param_1 + 0x1f8),local_28);
    if ((*(int *)(param_1 + 0x1f8) == 0) || (*(int *)(param_1 + 500) == 0)) {
      FUN_0041e91f(L"Fail to Program Handbrake!",L"Error",0x10);
      local_8 = local_8 & 0xffffff00;
      FUN_00404707();
      return;
    }
LAB_004044d0:
    iVar6 = *(int *)(param_1 + 500) + local_4c;
    _local_20 = CONCAT14((char)*(uint *)(param_1 + 0x1f8),local_20);
    if (0x20 < *(uint *)(param_1 + 0x1f8)) {
      FUN_00404c00(local_4c,0x20,iVar6);
      local_4c = local_4c + 0x20;
      *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) + -0x20;
      SendMessageW((HWND)*puVar9,0x402,(uint)(local_4c * 0x1e) / uStack_24 + 0x14,0);
      do {
        BVar5 = PeekMessageW(&local_48,(HWND)0x0,0,0,0);
        if (BVar5 == 0) goto LAB_004044d0;
        iVar6 = FUN_0042350a();
        iVar6 = (**(code **)(**(int **)(iVar6 + 4) + 0x5c))();
      } while (iVar6 != 0);
      PostQuitMessage(0);
      goto LAB_004044d0;
    }
    FUN_00404c00(local_4c,puStack_1c,iVar6);
    local_8 = 0;
  }
  _local_20 = CONCAT44(puVar9,local_20);
  SendMessageW((HWND)*puVar9,0x402,100,0);
  local_8._0_1_ = 5;
  local_28 = (undefined4 *)0x0;
  uStack_24 = 0x20;
  puVar9 = (undefined4 *)FUN_00405265(0x20);
  _local_28 = CONCAT44(uStack_24,puVar9);
  *puVar9 = 0;
  puVar9[1] = 0;
  puVar9[2] = 0;
  puVar9[3] = 0;
  puVar9[4] = 0;
  puVar9[5] = 0;
  puVar9[6] = 0;
  puVar9[7] = 0;
  local_8._0_1_ = 6;
  *(undefined1 *)puVar9 = 4;
  FUN_00402090(0xf1,&local_28);
  local_8._0_1_ = 5;
  if (local_28 != (undefined4 *)0x0) {
    thunk_FUN_005473a0(local_28);
  }
  *(undefined1 *)(param_1 + 0x1fc) = 0;
  Sleep(1);
  local_28 = (undefined4 *)0x0;
  uStack_24 = 0x20;
  puVar9 = (undefined4 *)FUN_00405265(0x20);
  _local_28 = CONCAT44(uStack_24,puVar9);
  *puVar9 = 0;
  puVar9[1] = 0;
  puVar9[2] = 0;
  puVar9[3] = 0;
  puVar9[4] = 0;
  puVar9[5] = 0;
  puVar9[6] = 0;
  puVar9[7] = 0;
  local_8 = CONCAT31(local_8._1_3_,7);
  *(undefined1 *)puVar9 = 1;
  FUN_00402090(0xf1,&local_28);
  if (local_28 != (undefined4 *)0x0) {
    thunk_FUN_005473a0(local_28);
  }
  uVar11 = 1;
  local_8 = 0;
  FUN_00422cae(0x3ef);
  FUN_00422c40(uVar11);
  Sleep(1);
  FUN_0041e91f(L"Update Complete!",L"Handbrake Updater",0x40);
  local_8 = 0xffffffff;
  LOCK();
  piVar1 = (int *)(iVar2 + -4);
  iVar6 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    (**(code **)(**(int **)(iVar2 + -0x10) + 4))((undefined4 *)(iVar2 + -0x10));
  }
  ExceptionList = local_10;
  return;
}



// FUNCTION Catch@004046bd @ 004046bd

undefined * Catch_004046bd(void)

{
  FUN_0041e91f(L"Update Fail!",L"Error",0x10);
  return &DAT_004046d7;
}



// FUNCTION Catch@004046e3 @ 004046e3

undefined * Catch_004046e3(void)

{
  FUN_00418240(L"Error!",0,0);
  return &DAT_004046f7;
}



// FUNCTION FUN_00404707 @ 00404707

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00404707(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_EAX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 uVar3;
  
  SendMessageW((HWND)*in_EAX,0x402,0,0);
  uVar3 = 1;
  FUN_00422cae(0x3ef);
  FUN_00422c40(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  LOCK();
  piVar1 = (int *)(unaff_ESI + -4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1 || iVar2 + -1 < 0) {
    (**(code **)(**(int **)(unaff_ESI + -0x10) + 4))((undefined4 *)(unaff_ESI + -0x10));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// FUNCTION FUN_00404770 @ 00404770

void FUN_00404770(void)

{
  FUN_0041438e();
  return;
}



// FUNCTION FUN_00404780 @ 00404780

int * __thiscall FUN_00404780(int *param_1,int *param_2)

{
  int *_Dst;
  int *piVar1;
  uint _Size;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  
  iVar3 = *param_1;
  iVar4 = *param_2;
  piVar8 = (int *)(iVar3 + -0x10);
  piVar7 = (int *)(iVar4 + -0x10);
  if (piVar7 != piVar8) {
    if ((-1 < *(int *)(iVar3 + -4)) && ((int *)*piVar7 == (int *)*piVar8)) {
      puVar6 = (undefined4 *)(**(code **)(*(int *)*piVar7 + 0x10))();
      if ((*(int *)(iVar4 + -4) < 0) || (puVar6 != (undefined4 *)*piVar7)) {
        piVar1 = (int *)(iVar4 + -0xc);
        piVar7 = (int *)(**(code **)*puVar6)(*piVar1,2);
        if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_00403350();
        }
        _Dst = piVar7 + 4;
        iVar5 = *piVar1;
        piVar7[1] = iVar5;
        _Size = iVar5 * 2 + 2;
        uVar2 = *piVar1 * 2 + 2;
        if (uVar2 != 0) {
          if (_Dst == (int *)0x0) {
            puVar6 = (undefined4 *)FUN_00549bed();
            *puVar6 = 0x16;
          }
          else {
            if ((iVar4 != 0) && (uVar2 <= _Size)) {
              FUN_00543940(_Dst,iVar4,uVar2);
              goto LAB_0040486b;
            }
            _memset(_Dst,0,_Size);
            if (iVar4 == 0) {
              puVar6 = (undefined4 *)FUN_00549bed();
              *puVar6 = 0x16;
            }
            else {
              if (uVar2 <= _Size) goto LAB_0040486b;
              puVar6 = (undefined4 *)FUN_00549bed();
              *puVar6 = 0x22;
            }
          }
          FUN_0054733f();
        }
      }
      else {
        LOCK();
        *(int *)(iVar4 + -4) = *(int *)(iVar4 + -4) + 1;
        UNLOCK();
      }
LAB_0040486b:
      piVar1 = (int *)(iVar3 + -4);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1 || iVar3 + -1 < 0) {
        (**(code **)(*(int *)*piVar8 + 4))(piVar8);
      }
      *param_1 = (int)(piVar7 + 4);
      return param_1;
    }
    FUN_00403020(iVar4,*(undefined4 *)(iVar4 + -0xc));
  }
  return param_1;
}



// FUNCTION FUN_004048c0 @ 004048c0

int * __thiscall FUN_004048c0(int *param_1,LPCSTR param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 != (LPCSTR)0x0) {
    iVar4 = MultiByteToWideChar(3,0,param_2,-1,(LPWSTR)0x0,0);
    iVar4 = iVar4 + -1;
    if (0 < iVar4) {
      if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - iVar4) < 0) {
        FUN_004033a0(iVar4);
      }
      MultiByteToWideChar(3,0,param_2,-1,(LPWSTR)*param_1,iVar4);
      if (iVar4 <= *(int *)(*param_1 + -8)) {
        *(int *)(*param_1 + -0xc) = iVar4;
        *(undefined2 *)(*param_1 + iVar4 * 2) = 0;
        return param_1;
      }
      goto LAB_00404989;
    }
  }
  iVar4 = *param_1;
  puVar1 = (undefined4 *)(iVar4 + -0x10);
  piVar3 = (int *)*puVar1;
  if (*(int *)(iVar4 + -0xc) != 0) {
    piVar2 = (int *)(iVar4 + -4);
    if (*(int *)(iVar4 + -4) < 0) {
      if (-1 < *(int *)(iVar4 + -8)) {
        *(undefined4 *)(iVar4 + -0xc) = 0;
        *(undefined2 *)*param_1 = 0;
        return param_1;
      }
LAB_00404989:
                    /* WARNING: Subroutine does not return */
      FUN_004024f0(0x80070057);
    }
    LOCK();
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 == 1 || iVar4 + -1 < 0) {
      (**(code **)(*(int *)*puVar1 + 4))(puVar1);
    }
    iVar4 = (**(code **)(*piVar3 + 0xc))();
    *param_1 = iVar4 + 0x10;
  }
  return param_1;
}



// FUNCTION FUN_004049a0 @ 004049a0

ExternalContextBase * __thiscall FUN_004049a0(ExternalContextBase *param_1,uint param_2)

{
  Concurrency::details::ExternalContextBase::~ExternalContextBase(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      thunk_FUN_005473a0(param_1);
      return param_1;
    }
    guard_check_icall(param_1,0x80);
  }
  return param_1;
}



// FUNCTION FUN_004049e0 @ 004049e0

ExternalContextBase * __thiscall FUN_004049e0(ExternalContextBase *param_1,uint param_2)

{
  Concurrency::details::ExternalContextBase::~ExternalContextBase(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      thunk_FUN_005473a0(param_1);
      return param_1;
    }
    guard_check_icall(param_1,0x80);
  }
  return param_1;
}



// FUNCTION FUN_00404a20 @ 00404a20

int * __thiscall FUN_00404a20(int *param_1,short *param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  short *psVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0056009d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)FUN_004062c5(DAT_005bffe4 ^ (uint)&stack0xfffffffc);
  if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_004024f0(0x80004005);
  }
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  *param_1 = iVar3 + 0x10;
  local_8 = 0;
  if (param_2 == (short *)0x0) {
    iVar3 = 0;
  }
  else {
    if (((uint)param_2 & 0xffff0000) == 0) {
      FUN_00402dd0((uint)param_2 & 0xffff);
      ExceptionList = local_10;
      return param_1;
    }
    psVar4 = param_2;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    iVar3 = (int)psVar4 - (int)(param_2 + 1) >> 1;
  }
  FUN_00403020(param_2,iVar3);
  ExceptionList = local_10;
  return param_1;
}



// FUNCTION FUN_00404ad0 @ 00404ad0

ExternalContextBase * __thiscall FUN_00404ad0(ExternalContextBase *param_1,uint param_2)

{
  Concurrency::details::ExternalContextBase::~ExternalContextBase(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      thunk_FUN_005473a0(param_1);
      return param_1;
    }
    guard_check_icall(param_1,0x80);
  }
  return param_1;
}



// FUNCTION FUN_00404b10 @ 00404b10

void __fastcall FUN_00404b10(int param_1)

{
  EnableWindow(*(HWND *)(param_1 + 0x20),0);
  return;
}



// FUNCTION FUN_00404b20 @ 00404b20

void __fastcall FUN_00404b20(int param_1)

{
  EnableWindow(*(HWND *)(param_1 + 0x20),1);
  return;
}



// FUNCTION FUN_00404b30 @ 00404b30

int * FUN_00404b30(int *param_1)

{
  int *_Dst;
  uint uVar1;
  uint _Size;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  puVar3 = (undefined4 *)(**(code **)(*(int *)*param_1 + 0x10))();
  if ((-1 < param_1[3]) && (puVar3 == (undefined4 *)*param_1)) {
    LOCK();
    param_1[3] = param_1[3] + 1;
    UNLOCK();
    return param_1;
  }
  piVar4 = (int *)(**(code **)*puVar3)(param_1[1],2);
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_00403350();
  }
  iVar2 = param_1[1];
  piVar4[1] = iVar2;
  uVar1 = param_1[1] * 2 + 2;
  param_1 = param_1 + 4;
  _Size = iVar2 * 2 + 2;
  _Dst = piVar4 + 4;
  if (uVar1 != 0) {
    if (_Dst != (int *)0x0) {
      if ((param_1 != (int *)0x0) && (uVar1 <= _Size)) {
        FUN_00543940(_Dst,param_1,uVar1);
        return piVar4;
      }
      _memset(_Dst,0,_Size);
      if (param_1 != (int *)0x0) {
        if (uVar1 <= _Size) {
          return piVar4;
        }
        puVar3 = (undefined4 *)FUN_00549bed();
        *puVar3 = 0x22;
        FUN_0054733f();
        return piVar4;
      }
    }
    puVar3 = (undefined4 *)FUN_00549bed();
    *puVar3 = 0x16;
    FUN_0054733f();
    return piVar4;
  }
  return piVar4;
}



// FUNCTION FUN_00404c00 @ 00404c00

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00404c00(undefined4 *param_1,undefined4 param_2,byte param_3,undefined4 param_4)

{
  undefined1 *_Dst;
  BOOL BVar1;
  DWORD DVar2;
  uint _Size;
  char *pcVar3;
  undefined1 local_44 [12];
  _OVERLAPPED local_38;
  DWORD local_24;
  undefined1 local_20 [4];
  longlong local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005602ed;
  local_10 = ExceptionList;
  local_14 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Size = (uint)*(ushort *)((int)param_1 + 0xe);
  local_38.hEvent = (HANDLE)0x0;
  local_38.Internal = 0;
  local_38.InternalHigh = 0;
  local_38.u.s.Offset = 0;
  local_38.u.s.OffsetHigh = 0;
  if ((int)(_Size - 6) < (int)(uint)param_3) {
    FUN_00401b70("Buffer too big");
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_005badf0);
  }
  local_1c = (ulonglong)*(ushort *)((int)param_1 + 0xe) << 0x20;
  _Dst = (undefined1 *)FUN_00405265(_Size,local_14);
  local_1c = CONCAT44(local_1c._4_4_,_Dst);
  _memset(_Dst,0,_Size);
  local_8 = 0;
  if ((((_Size != 0) && (*_Dst = 0xf2, 1 < _Size)) && (_Dst[1] = 10, 2 < _Size)) &&
     (_Dst[2] = param_3, 3 < _Size)) {
    _Dst[3] = (char)param_2;
    if (((4 < _Size) && (_Dst[4] = (char)((uint)param_2 >> 8), 5 < _Size)) &&
       (_Dst[5] = (char)((uint)param_2 >> 0x10), 6 < _Size)) {
      _Dst[6] = (char)((uint)param_2 >> 0x18);
      FUN_00543940(_Dst + 7,param_4,(uint)param_3);
      BVar1 = WriteFile((HANDLE)*param_1,_Dst,(uint)*(ushort *)((int)param_1 + 0xe),(LPDWORD)0x0,
                        &local_38);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        if (DVar2 != 0x3e5) {
          pcVar3 = "WriteFile fail.";
          goto LAB_00404d8a;
        }
      }
      BVar1 = GetOverlappedResult((HANDLE)*param_1,&local_38,&local_24,1);
      if (BVar1 != 0) {
        thunk_FUN_005473a0(_Dst);
        ExceptionList = local_10;
        return;
      }
      pcVar3 = "GetOverlappedResult fail.";
      goto LAB_00404d8a;
    }
  }
  pcVar3 = "index out of range";
LAB_00404d8a:
  FUN_00401b70(pcVar3);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_44,&DAT_005badf0);
}



// FUNCTION FUN_00404db0 @ 00404db0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_00404db0(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  HDEVINFO DeviceInfoSet;
  undefined4 uVar3;
  int iVar4;
  BOOL BVar5;
  DWORD DVar6;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_W DeviceInterfaceDetailData;
  undefined4 *puVar7;
  DWORD local_54;
  DWORD local_4c;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_W local_48;
  GUID local_44;
  _SP_DEVICE_INTERFACE_DATA local_34;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00560335;
  local_10 = ExceptionList;
  uVar2 = DAT_005bffe4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar7 = (undefined4 *)*param_1;
  puVar1 = (undefined4 *)param_1[1];
  local_14 = uVar2;
  if (puVar7 != puVar1) {
    do {
      local_18 = (undefined4 *)*puVar7;
      if (local_18 != (undefined4 *)0x0) {
        FUN_00401c60(uVar2);
        FUN_00541f12(local_18,0x94);
      }
      puVar7 = puVar7 + 1;
    } while (puVar7 != puVar1);
    param_1[1] = *param_1;
  }
  local_44.Data1 = 0;
  local_44.Data2 = 0;
  local_44.Data3 = 0;
  local_44.Data4[0] = '\0';
  local_44.Data4[1] = '\0';
  local_44.Data4[2] = '\0';
  local_44.Data4[3] = '\0';
  local_44.Data4[4] = '\0';
  local_44.Data4[5] = '\0';
  local_44.Data4[6] = '\0';
  local_44.Data4[7] = '\0';
  HidD_GetHidGuid(&local_44);
  DeviceInfoSet = SetupDiGetClassDevsW(&local_44,(PCWSTR)0x0,(HWND)0x0,0x12);
  if (DeviceInfoSet == (HDEVINFO)0x0) {
    uVar3 = FUN_00402410();
  }
  else {
    local_54 = 0;
    local_34.cbSize = 0x1c;
    local_34.InterfaceClassGuid.Data1 = 0;
    local_34.InterfaceClassGuid.Data2 = 0;
    local_34.InterfaceClassGuid.Data3 = 0;
    local_34.InterfaceClassGuid.Data4[0] = '\0';
    local_34.InterfaceClassGuid.Data4[1] = '\0';
    local_34.InterfaceClassGuid.Data4[2] = '\0';
    local_34.InterfaceClassGuid.Data4[3] = '\0';
    local_34.InterfaceClassGuid.Data4[4] = '\0';
    local_34.InterfaceClassGuid.Data4[5] = '\0';
    local_34.InterfaceClassGuid.Data4[6] = '\0';
    local_34.InterfaceClassGuid.Data4[7] = '\0';
    local_34.Flags = 0;
    local_34.Reserved = 0;
    iVar4 = SetupDiEnumDeviceInterfaces(DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,&local_44,0,&local_34);
    while (iVar4 != 0) {
      local_4c = 0;
      BVar5 = SetupDiGetDeviceInterfaceDetailW
                        (DeviceInfoSet,&local_34,(PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0,0,&local_4c
                         ,(PSP_DEVINFO_DATA)0x0);
      if ((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0x7a)) goto LAB_00405043;
      DeviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)FUN_00405265(local_4c);
      local_8 = 0;
      local_48 = DeviceInterfaceDetailData;
      _memset(DeviceInterfaceDetailData,0,local_4c);
      DeviceInterfaceDetailData->cbSize = 6;
      BVar5 = SetupDiGetDeviceInterfaceDetailW
                        (DeviceInfoSet,&local_34,DeviceInterfaceDetailData,local_4c,&local_4c,
                         (PSP_DEVINFO_DATA)0x0);
      if (BVar5 != 0) {
        puVar7 = (undefined4 *)FUN_0040526e(0x94);
        if (puVar7 == (undefined4 *)0x0) {
          puVar7 = (undefined4 *)0x0;
        }
        else {
          *(undefined8 *)(puVar7 + 0x16) = 0;
          *(undefined8 *)(puVar7 + 0x1c) = 0;
          *(undefined8 *)(puVar7 + 0x22) = 0;
          puVar7[0x24] = 0;
          *puVar7 = 0;
          puVar7[1] = 0;
          _memset(puVar7 + 2,0,0x40);
          puVar7[0x12] = 0;
          puVar7[0x13] = 0;
          puVar7[0x14] = 0;
          puVar7[0x15] = 0;
          puVar7[0x16] = 0;
          puVar7[0x17] = 7;
          *(undefined2 *)(puVar7 + 0x12) = 0;
          puVar7[0x18] = 0;
          puVar7[0x19] = 0;
          puVar7[0x1a] = 0;
          puVar7[0x1b] = 0;
          puVar7[0x1c] = 0;
          puVar7[0x1d] = 7;
          *(undefined2 *)(puVar7 + 0x18) = 0;
          puVar7[0x1e] = 0;
          puVar7[0x1f] = 0;
          puVar7[0x20] = 0;
          puVar7[0x21] = 0;
          puVar7[0x22] = 0;
          puVar7[0x23] = 7;
          *(undefined2 *)(puVar7 + 0x1e) = 0;
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        local_18 = puVar7;
        iVar4 = FUN_00401d80(DeviceInterfaceDetailData->DevicePath);
        if (-1 < iVar4) {
          puVar1 = (undefined4 *)param_1[1];
          if (puVar1 != (undefined4 *)param_1[2]) {
            *puVar1 = puVar7;
            param_1[1] = param_1[1] + 4;
            goto LAB_00404ff0;
          }
          FUN_00405080(puVar1,&local_18);
          puVar7 = local_18;
        }
        if (puVar7 != (undefined4 *)0x0) {
          FUN_00401c60();
          FUN_00541f12(puVar7,0x94);
        }
      }
LAB_00404ff0:
      local_54 = local_54 + 1;
      local_8 = 0xffffffff;
      if (DeviceInterfaceDetailData != (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0) {
        thunk_FUN_005473a0(DeviceInterfaceDetailData);
      }
      local_34.cbSize = 0x1c;
      local_34.InterfaceClassGuid.Data1 = 0;
      local_34.InterfaceClassGuid.Data2 = 0;
      local_34.InterfaceClassGuid.Data3 = 0;
      local_34.InterfaceClassGuid.Data4[0] = '\0';
      local_34.InterfaceClassGuid.Data4[1] = '\0';
      local_34.InterfaceClassGuid.Data4[2] = '\0';
      local_34.InterfaceClassGuid.Data4[3] = '\0';
      local_34.InterfaceClassGuid.Data4[4] = '\0';
      local_34.InterfaceClassGuid.Data4[5] = '\0';
      local_34.InterfaceClassGuid.Data4[6] = '\0';
      local_34.InterfaceClassGuid.Data4[7] = '\0';
      local_34.Flags = 0;
      local_34.Reserved = 0;
      iVar4 = SetupDiEnumDeviceInterfaces
                        (DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,&local_44,local_54,&local_34);
    }
    GetLastError();
LAB_00405043:
    SetupDiDestroyDeviceInfoList(DeviceInfoSet);
    uVar3 = 0;
  }
  ExceptionList = local_10;
  return uVar3;
}



// FUNCTION FUN_00405070 @ 00405070

void __fastcall FUN_00405070(int *param_1)

{
  if (*param_1 != 0) {
    thunk_FUN_005473a0(*param_1);
  }
  return;
}



// FUNCTION FUN_00405080 @ 00405080

undefined4 * __thiscall FUN_00405080(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  
  iVar3 = *param_1;
  iVar8 = param_1[1] - iVar3 >> 2;
  if (iVar8 != 0x3fffffff) {
    uVar9 = param_1[2] - iVar3 >> 2;
    uVar1 = iVar8 + 1;
    if (uVar9 <= 0x3fffffff - (uVar9 >> 1)) {
      uVar9 = (uVar9 >> 1) + uVar9;
      uVar10 = uVar1;
      if (uVar1 <= uVar9) {
        uVar10 = uVar9;
      }
      if (uVar10 < 0x40000000) {
        uVar9 = uVar10 * 4;
        if (uVar9 < 0x1000) {
          if (uVar9 == 0) {
            puVar13 = (undefined4 *)0x0;
          }
          else {
            puVar13 = (undefined4 *)FUN_0040526e(uVar9);
          }
        }
        else {
          if (uVar9 + 0x23 <= uVar9) goto LAB_00405239;
          iVar8 = FUN_0040526e(uVar9 + 0x23);
          if (iVar8 == 0) goto LAB_00405243;
          puVar13 = (undefined4 *)(iVar8 + 0x23U & 0xffffffe0);
          puVar13[-1] = iVar8;
        }
        uVar4 = *param_3;
        *param_3 = 0;
        puVar2 = puVar13 + ((int)param_2 - iVar3 >> 2);
        *puVar2 = uVar4;
        puVar5 = (undefined4 *)param_1[1];
        puVar11 = (undefined4 *)*param_1;
        puVar7 = puVar13;
        if (param_2 == puVar5) {
          for (; puVar11 != puVar5; puVar11 = puVar11 + 1) {
            uVar4 = *puVar11;
            *puVar11 = 0;
            *puVar7 = uVar4;
            puVar7 = puVar7 + 1;
          }
        }
        else {
          for (; puVar11 != param_2; puVar11 = puVar11 + 1) {
            uVar4 = *puVar11;
            *puVar11 = 0;
            *puVar7 = uVar4;
            puVar7 = puVar7 + 1;
          }
          puVar5 = (undefined4 *)param_1[1];
          if (param_2 != puVar5) {
            puVar11 = param_2;
            do {
              uVar4 = *puVar11;
              *puVar11 = 0;
              *(undefined4 *)((int)puVar11 + (int)puVar2 + (4 - (int)param_2)) = uVar4;
              puVar11 = puVar11 + 1;
            } while (puVar11 != puVar5);
          }
        }
        piVar12 = (int *)*param_1;
        if (piVar12 != (int *)0x0) {
          piVar6 = (int *)param_1[1];
          for (; piVar12 != piVar6; piVar12 = piVar12 + 1) {
            iVar3 = *piVar12;
            if (iVar3 != 0) {
              FUN_00401c60();
              FUN_00541f12(iVar3,0x94);
            }
          }
          iVar3 = *param_1;
          uVar9 = param_1[2] - iVar3 & 0xfffffffc;
          iVar8 = iVar3;
          if (0xfff < uVar9) {
            iVar8 = *(int *)(iVar3 + -4);
            uVar9 = uVar9 + 0x23;
            if (0x1f < (iVar3 - iVar8) - 4U) goto LAB_00405243;
          }
          FUN_00541f12(iVar8,uVar9);
        }
        *param_1 = (int)puVar13;
        param_1[1] = (int)(puVar13 + uVar1);
        param_1[2] = (int)(puVar13 + uVar10);
        return puVar2;
      }
    }
LAB_00405239:
    FUN_004023d0();
  }
  FUN_00405250();
LAB_00405243:
                    /* WARNING: Subroutine does not return */
  FUN_0054734f();
}



// FUNCTION FUN_00405250 @ 00405250

void FUN_00405250(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_005432f9("vector too long");
}



// FUNCTION thunk_FUN_005473a0 @ 0040525b

void thunk_FUN_005473a0(undefined4 param_1)

{
  FUN_00554881(param_1,0);
  return;
}



// FUNCTION thunk_FUN_005473a0 @ 00405260

void thunk_FUN_005473a0(undefined4 param_1)

{
  FUN_00554881(param_1,0);
  return;
}



// FUNCTION FUN_00405265 @ 00405265

void FUN_00405265(void)

{
  FUN_0040526e();
  return;
}



// FUNCTION FUN_0040526e @ 0040526e

int FUN_0040526e(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = FUN_00549cb0(param_1);
  puVar1 = PTR_thunk_FUN_00405d92_005bf45c;
  if ((iVar2 == 0) && (PTR_thunk_FUN_00405d92_005bf45c != (undefined *)0x0)) {
    (*(code *)PTR_guard_check_icall_0056f990)(param_1);
    iVar2 = (*(code *)puVar1)();
    return iVar2;
  }
  return iVar2;
}



// FUNCTION FUN_004052a6 @ 004052a6

undefined4 * __fastcall FUN_004052a6(undefined4 *param_1)

{
  FUN_00405d3a();
  param_1[2] = 0;
  *param_1 = COleException::vftable;
  return param_1;
}



// FUNCTION `scalar_deleting_destructor' @ 004052bc

/* Library Function - Single Match
    public: virtual void * __thiscall COleException::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall COleException::_scalar_deleting_destructor_(COleException *this,uint param_1)

{
  *(undefined ***)this = vftable;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_005473a0(this);
    }
    else {
      guard_check_icall(this,0xc);
    }
  }
  return this;
}



// FUNCTION FUN_004052ed @ 004052ed

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_004052ed(HMENU param_1,HMENU param_2,UINT *param_3,int param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  HMENU hMenu;
  UINT UVar3;
  int iVar4;
  undefined4 uVar5;
  UINT uPosition;
  WCHAR *lpNewItem;
  HMENU local_22c;
  UINT local_224;
  LPCWSTR local_21c;
  UINT local_218;
  WCHAR local_214 [262];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x230;
  local_8 = 0x4052fc;
  bVar1 = false;
  iVar2 = GetMenuItemCount(param_2);
  uPosition = 0;
  local_218 = 0;
  if (param_4 == 1) {
    uPosition = *param_3;
  }
  local_224 = 0;
  if (0 < iVar2) {
    do {
      hMenu = GetSubMenu(param_2,local_224);
      UVar3 = GetMenuState(param_2,local_224,0x400);
      if ((hMenu == (HMENU)0x0) && ((UVar3 & 0x800) != 0)) {
        param_3[param_4] = local_218;
        local_218 = 0;
        if (param_4 < 5) {
          uPosition = uPosition + param_3[param_4 + 1];
        }
        param_4 = param_4 + 2;
      }
      else {
        local_22c = (HMENU)0x0;
        if ((param_5 != 0) && ((param_4 == 5 && (param_3[5] == 1)))) {
          local_22c = GetSubMenu(param_1,uPosition);
        }
        iVar4 = GetMenuStringW(param_2,local_224,local_214,0x100,0x400);
        if (hMenu == (HMENU)0x0) {
          if (0 < iVar4) {
            lpNewItem = local_214;
            hMenu = (HMENU)GetMenuItemID(param_2,local_224);
            UVar3 = UVar3 | 0x400;
LAB_00405519:
            InsertMenuW(param_1,uPosition,UVar3,(UINT_PTR)hMenu,lpNewItem);
            uPosition = uPosition + 1;
            local_218 = local_218 + 1;
          }
        }
        else if (local_22c == (HMENU)0x0) {
          iVar4 = GetMenuItemCount(hMenu);
          if (iVar4 != 0) {
            lpNewItem = local_214;
            UVar3 = UVar3 & 0xff | 0x410;
            goto LAB_00405519;
          }
        }
        else {
          iVar4 = FUN_0042350a();
          FUN_00404a20(*(undefined4 *)(iVar4 + 0x10));
          local_8 = 0;
          if (*(int *)(local_21c + -6) != 0) {
            ATL::CSimpleStringT<wchar_t,0>::AppendChar((CSimpleStringT<wchar_t,0> *)&local_21c,L' ')
            ;
          }
          uVar5 = FUN_00549df8(local_214);
          FUN_00405658(local_214,uVar5);
          AppendMenuW(local_22c,0x10,(UINT_PTR)hMenu,local_21c);
          param_3[param_4] = 0;
          param_3[param_4 + -1] = param_3[param_4 + -1] + 1;
          local_8 = 0xffffffff;
          bVar1 = true;
          FUN_00403680();
        }
      }
      local_224 = local_224 + 1;
    } while ((int)local_224 < iVar2);
    if (bVar1) goto LAB_004054e5;
  }
  param_3[param_4] = local_218;
LAB_004054e5:
  FUN_0054236a();
  return;
}


// SYMBOL FindResourceExW @ EXTERNAL:0000002d
// XREF 0056f2b0 DATA
// XREF 005186c9 COMPUTED_CALL
// SYMBOL WriteFile @ EXTERNAL:00000087
// XREF 0056f418 DATA
// XREF 00559303 COMPUTED_CALL
// XREF 00558ba2 COMPUTED_CALL
// XREF 00558bea COMPUTED_CALL
// XREF 00404d09 COMPUTED_CALL
// XREF 004b4d6f COMPUTED_CALL
// XREF 00558e38 COMPUTED_CALL
// XREF 00558f21 COMPUTED_CALL
// XREF 00559049 COMPUTED_CALL
// SYMBOL FindResourceW @ EXTERNAL:0000008b
// XREF 0056f428 DATA
// XREF 00437843 COMPUTED_CALL
// XREF 0050f8c8 COMPUTED_CALL
// XREF 004b747e COMPUTED_CALL
// XREF 0042f5e2 COMPUTED_CALL
// XREF 0041e8c9 COMPUTED_CALL
// XREF 00402cc8 COMPUTED_CALL
// XREF 00402dfc COMPUTED_CALL
// XREF 0041de66 COMPUTED_CALL
// XREF 004a8ed3 COMPUTED_CALL
// XREF 00404471 COMPUTED_CALL
// XREF 0041432a COMPUTED_CALL
// XREF 00414407 COMPUTED_CALL
// XREF 004143c5 COMPUTED_CALL
// XREF 005186e4 COMPUTED_CALL
// XREF 00414772 COMPUTED_CALL
// SYMBOL LoadResource @ EXTERNAL:0000008c
// XREF 0056f42c DATA
// XREF 00437853 COMPUTED_CALL
// XREF 0050f8d8 COMPUTED_CALL
// XREF 004b7493 COMPUTED_CALL
// XREF 0042f5f0 COMPUTED_CALL
// XREF 0041e8e7 COMPUTED_CALL
// XREF 00402cdc COMPUTED_CALL
// XREF 00402e0f COMPUTED_CALL
// XREF 0041de72 COMPUTED_CALL
// XREF 00404492 COMPUTED_CALL
// XREF 00414338 COMPUTED_CALL
// XREF 00414413 COMPUTED_CALL
// XREF 004143d1 COMPUTED_CALL
// XREF 005186f0 COMPUTED_CALL
// XREF 0041477e COMPUTED_CALL
// SYMBOL LockResource @ EXTERNAL:0000008d
// XREF 0056f430 DATA
// XREF 00437862 COMPUTED_CALL
// XREF 0050f8e7 COMPUTED_CALL
// XREF 004b74a5 COMPUTED_CALL
// XREF 0042f5fb COMPUTED_CALL
// XREF 0041e8f2 COMPUTED_CALL
// XREF 00402cf0 COMPUTED_CALL
// XREF 00402e1e COMPUTED_CALL
// XREF 0041de7d COMPUTED_CALL
// XREF 00404499 COMPUTED_CALL
// XREF 00414345 COMPUTED_CALL
// XREF 0041441e COMPUTED_CALL
// XREF 0041465f COMPUTED_CALL
// XREF 0041478e COMPUTED_CALL
// SYMBOL SizeofResource @ EXTERNAL:0000008e
// XREF 0056f434 DATA
// XREF 0042f609 COMPUTED_CALL
// XREF 0041e8db COMPUTED_CALL
// XREF 00402d00 COMPUTED_CALL
// XREF 00402e34 COMPUTED_CALL
// XREF 00404481 COMPUTED_CALL
// SYMBOL ReadFile @ EXTERNAL:00000099
// XREF 0056f460 DATA
// XREF 004b4b97 COMPUTED_CALL
// SYMBOL HideCaret @ EXTERNAL:0000016b
// XREF 0056f858 DATA
// XREF 00521f80 COMPUTED_CALL
// SYMBOL HidD_SetNumInputBuffers @ EXTERNAL:00000241
// XREF 0056f1c0 DATA
// XREF 00401fa0 COMPUTED_CALL
// SYMBOL HidD_FreePreparsedData @ EXTERNAL:00000242
// XREF 0056f1c4 DATA
// XREF 00401c6b COMPUTED_CALL
// SYMBOL HidD_GetFeature @ EXTERNAL:00000243
// XREF 0056f1c8 DATA
// XREF 0040204d COMPUTED_CALL
// SYMBOL HidD_SetFeature @ EXTERNAL:00000244
// XREF 0056f1cc DATA
// XREF 00402133 COMPUTED_CALL
// SYMBOL HidD_GetPreparsedData @ EXTERNAL:00000245
// XREF 0056f1d0 DATA
// XREF 00401dd2 COMPUTED_CALL
// SYMBOL HidP_GetCaps @ EXTERNAL:00000246
// XREF 0056f1d4 DATA
// XREF 00401de6 COMPUTED_CALL
// SYMBOL HidD_GetProductString @ EXTERNAL:00000247
// XREF 0056f1d8 DATA
// XREF 00401e18 COMPUTED_CALL
// SYMBOL HidD_GetManufacturerString @ EXTERNAL:00000248
// XREF 0056f1dc DATA
// XREF 00401e73 COMPUTED_CALL
// SYMBOL HidD_GetSerialNumberString @ EXTERNAL:00000249
// XREF 0056f1e0 DATA
// XREF 00401ed3 COMPUTED_CALL
// SYMBOL HidD_GetAttributes @ EXTERNAL:0000024a
// XREF 0056f1e4 DATA
// XREF 00401f32 COMPUTED_CALL
// SYMBOL HidD_GetHidGuid @ EXTERNAL:0000024b
// XREF 0056f1e8 DATA
// XREF 00404e2a COMPUTED_CALL
// SYMBOL AfxLoadLangResourceDLL @ 00406a9f
// XREF 00407044 UNCONDITIONAL_CALL
// SYMBOL HideApplication @ 0041b682
// XREF 004ba604 UNCONDITIONAL_CALL
// SYMBOL GetResourceOffset @ 004368cc
// XREF 0043710d UNCONDITIONAL_CALL
// SYMBOL ?GetResourceOffset@CMFCToolBarImages@@QBEHI@Z @ 004368cc
// XREF 0043710d UNCONDITIONAL_CALL
// SYMBOL LoadResource @ 004b5a07
// XREF 0041e8fd UNCONDITIONAL_CALL
// SYMBOL ?LoadResource@CMFCDynamicLayout@@SAHPAVCWnd@@PAXK@Z @ 004b5a07
// XREF 0041e8fd UNCONDITIONAL_CALL
// SYMBOL HideAll @ 004c01c2
// XREF 00585878 DATA
// SYMBOL HidePlace @ 004dcbbb
// XREF 004dbed8 UNCONDITIONAL_CALL
// XREF 004dbe13 UNCONDITIONAL_CALL
// XREF 004431e1 UNCONDITIONAL_CALL
// SYMBOL HideKeyTips @ 004e94ef
// XREF 00452512 UNCONDITIONAL_CALL
// XREF 00457827 UNCONDITIONAL_CALL
// XREF 0047793a UNCONDITIONAL_CALL
// XREF 00478302 UNCONDITIONAL_CALL
// XREF 0047eaf9 UNCONDITIONAL_CALL
// SYMBOL Hide @ 004eae29
// XREF 004e950c UNCONDITIONAL_CALL
// XREF 004eab92 UNCONDITIONAL_CALL
// SYMBOL Hide @ 005037de
// XREF 00503a93 UNCONDITIONAL_CALL
// XREF 00521840 UNCONDITIONAL_CALL
// XREF 005037cd UNCONDITIONAL_CALL
// XREF 005219fe UNCONDITIONAL_CALL
// SYMBOL Hide @ 00532cbc
// XREF 00532e6d UNCONDITIONAL_CALL
// XREF 00532f1f UNCONDITIONAL_CALL
// XREF 004dd1e9 UNCONDITIONAL_CALL
// XREF 004dcf12 UNCONDITIONAL_CALL
// XREF 004dcbc4 UNCONDITIONAL_CALL
// SYMBOL PTR_FindResourceExW_0056f2b0 @ 0056f2b0
// XREF 005186c9 READ
// SYMBOL PTR_FindResourceW_0056f428 @ 0056f428
// XREF 00402dfc READ
// XREF 004b747e READ
// XREF 0042f5e2 READ
// XREF 005186e4 READ
// XREF 00402cc8 READ
// XREF 00414772 READ
// XREF 0041de66 READ
// XREF 0041e8c9 READ
// XREF 00404471 READ
// XREF 004143c5 READ
// XREF 0041432a READ
// XREF 00414407 READ
// XREF 00437843 READ
// XREF 004a8ed3 READ
// XREF 0050f8c8 READ
// SYMBOL PTR_LoadResource_0056f42c @ 0056f42c
// XREF 00402e0f READ
// XREF 004b7493 READ
// XREF 0042f5f0 READ
// XREF 005186f0 READ
// XREF 00402cdc READ
// XREF 0041477e READ
// XREF 0041de72 READ
// XREF 0041e8e7 READ
// XREF 00404492 READ
// XREF 004143d1 READ
// XREF 00414338 READ
// XREF 00414413 READ
// XREF 00437853 READ
// XREF 0050f8d8 READ
// SYMBOL PTR_LockResource_0056f430 @ 0056f430
// XREF 00402e1e READ
// XREF 004b74a5 READ
// XREF 0042f5fb READ
// XREF 00402cf0 READ
// XREF 0041478e READ
// XREF 0041de7d READ
// XREF 0041e8f2 READ
// XREF 00404499 READ
// XREF 0041465f READ
// XREF 00414345 READ
// XREF 0041441e READ
// XREF 00437862 READ
// XREF 0050f8e7 READ
// SYMBOL PTR_SizeofResource_0056f434 @ 0056f434
// XREF 00402e34 READ
// XREF 0042f609 READ
// XREF 00402d00 READ
// XREF 0041e8db READ
// XREF 00404481 READ
// SYMBOL PTR_s_CResourceException_00572870 @ 00572870
// XREF 00419229 DATA
// SYMBOL s_CResourceException_00572c04 @ 00572c04
// XREF 00572870 DATA
// SYMBOL PTR_s_CD2DResource_00575fb8 @ 00575fb8
// XREF 00427087 DATA
// XREF 00426d1c DATA
// SYMBOL s_CD2DResource_005760bc @ 005760bc
// XREF 00575fb8 DATA
// SYMBOL ResourceRetValue @ ffdfffe0
