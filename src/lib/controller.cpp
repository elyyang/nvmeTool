/********************************************************************************************
*  _  ___   ____  __    _____         _ _  ___ _   
* | \| \ \ / /  \/  |__|_   _|__  ___| | |/ (_) |_ 
* | .` |\ V /| |\/| / -_)| |/ _ \/ _ \ | ' <| |  _|
* |_|\_| \_/ |_|  |_\___||_|\___/\___/_|_|\_\_|\__|
*                                                              
* MIT License
* 
* Copyright (c) 2026 Eric L. Yang
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
* https://github.com/elyyang
* elyyang@gmail.com
*
*********************************************************************************************/

#include "controller.h"

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

controller_c::controller_c(void)
{
}

controller_c::~controller_c(void)    
{	
}

controller_c& controller_c::getInstance(void)
{
    static controller_c mInstance;
    return mInstance;
}


cap_t controller_c::getControllerCapabilities(uio_c& uioDrv) const     
{
    cap_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cap_t), CONTROLLER_REG_OFFSET_CAP);
    return shadowReg;
}

vs_t controller_c::getVersion(uio_c& uioDrv) const
{
    vs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(vs_t), CONTROLLER_REG_OFFSET_VS);
    return shadowReg;
}

intms_t controller_c::getInterruptMaskSet(uio_c& uioDrv) const
{
    intms_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(intms_t), CONTROLLER_REG_OFFSET_INTMS);
    return shadowReg;
}

intmc_t controller_c::getInterruptMaskClear(uio_c& uioDrv) const
{
    intmc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(intmc_t), CONTROLLER_REG_OFFSET_INTMC);
    return shadowReg;
}

cc_t controller_c::getControllerConfiguration(uio_c& uioDrv) const
{
    cc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cc_t), CONTROLLER_REG_OFFSET_CC);
    return shadowReg;
}

csts_t controller_c::getControllerStatus(uio_c& uioDrv) const
{
    csts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(csts_t), CONTROLLER_REG_OFFSET_CSTS);
    return shadowReg;
}

nssr_t controller_c::getNvmSubsystemReset(uio_c& uioDrv) const
{
    nssr_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(nssr_t), CONTROLLER_REG_OFFSET_NSSR);
    return shadowReg;
}

aqa_t controller_c::getAdminQueueAttributes(uio_c& uioDrv) const
{
    aqa_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(aqa_t), CONTROLLER_REG_OFFSET_AQA);
    return shadowReg;
}

asq_t controller_c::getAdminSubmissionQueueBaseAddress(uio_c& uioDrv) const
{
    asq_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(asq_t), CONTROLLER_REG_OFFSET_ASQ);
    return shadowReg;
}

acq_t controller_c::getAdminCompletionQueueBaseAddress(uio_c& uioDrv) const
{
    acq_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(acq_t), CONTROLLER_REG_OFFSET_ACQ);
    return shadowReg;
}

cmbloc_t controller_c::getControllerMemoryBufferLocation(uio_c& uioDrv) const
{
    cmbloc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbloc_t), CONTROLLER_REG_OFFSET_CMBLOC);
    return shadowReg;
}

cmbsz_t controller_c::getControllerMemoryBufferSize(uio_c& uioDrv) const
{
    cmbsz_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbsz_t), CONTROLLER_REG_OFFSET_CMBSZ);
    return shadowReg;
}

bpinfo_t controller_c::getBootParitionInformation(uio_c& uioDrv) const
{
    bpinfo_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bpinfo_t), CONTROLLER_REG_OFFSET_BPINFO);
    return shadowReg;
}

bprsel_t controller_c::getBootParitionReadSelect(uio_c& uioDrv) const
{
    bprsel_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bprsel_t), CONTROLLER_REG_OFFSET_BPRSEL);
    return shadowReg;
}

bpmbl_t controller_c::getBootParitionMemoryBufferLocation(uio_c& uioDrv) const
{
    bpmbl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bpmbl_t), CONTROLLER_REG_OFFSET_BPMBL);
    return shadowReg;
}

cmbmsc_t controller_c::getControllerMemoryBufferMemorySpaceControl(uio_c& uioDrv) const
{
    cmbmsc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbmsc_t), CONTROLLER_REG_OFFSET_CMBMSC);
    return shadowReg;
}

cmbsts_t controller_c::getControllerMemoryBufferStatus(uio_c& uioDrv) const
{
    cmbsts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbsts_t), CONTROLLER_REG_OFFSET_CMBSTS);
    return shadowReg;
}

cmbebs_t controller_c::getControllerMemoryBufferElasticityBufferSize(uio_c& uioDrv) const
{
    cmbebs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbebs_t), CONTROLLER_REG_OFFSET_CMBEBS);
    return shadowReg;
}

cmbswtp_t controller_c::getControllerMemoryBufferSustainedWriteThroughput(uio_c& uioDrv) const
{
    cmbswtp_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbswtp_t), CONTROLLER_REG_OFFSET_CMBSWTP);
    return shadowReg;
}

nssd_t controller_c::getNvmSubsystemShutdown(uio_c& uioDrv) const
{
    nssd_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(nssd_t), CONTROLLER_REG_OFFSET_NSSD);
    return shadowReg;
}

crto_t controller_c::getControllerReadyTimeout(uio_c& uioDrv) const
{
    crto_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(crto_t), CONTROLLER_REG_OFFSET_CRTO);
    return shadowReg;
}

pmrcap_t controller_c::getPersistentMemoryCapabilities(uio_c& uioDrv) const
{
    pmrcap_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrcap_t), CONTROLLER_REG_OFFSET_PMRCAP);
    return shadowReg;
}

pmrctl_t controller_c::getPersistentMemoryRegionControl(uio_c& uioDrv) const
{
    pmrctl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrctl_t), CONTROLLER_REG_OFFSET_PMRCTL);
    return shadowReg;
}

pmrsts_t controller_c::getPersistentMemoryRegionStatus(uio_c& uioDrv) const
{
    pmrsts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrsts_t), CONTROLLER_REG_OFFSET_PMRSTS);
    return shadowReg;
}

pmrebs_t controller_c::getPersistentMemoryRegionElasticityBufferSize(uio_c& uioDrv) const
{
    pmrebs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrebs_t), CONTROLLER_REG_OFFSET_PMREBS);
    return shadowReg;
}

pmrswtp_t controller_c::getPersistentMemorySustainedWriteThroughput(uio_c& uioDrv) const
{
    pmrswtp_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrswtp_t), CONTROLLER_REG_OFFSET_PMRSWTP);
    return shadowReg;
}

pmrmscl_t controller_c::getPersistentMemoryRegionControllerMemorySpaceControlLower(uio_c& uioDrv) const
{
    pmrmscl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrmscl_t), CONTROLLER_REG_OFFSET_PMRMSCL);
    return shadowReg;
}

pmrmscu_t controller_c::getPersistentMemoryRegionControllerMemorySpaceControlUpper(uio_c& uioDrv) const
{
    pmrmscu_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrmscu_t), CONTROLLER_REG_OFFSET_PMRMSCU);
    return shadowReg;
}
