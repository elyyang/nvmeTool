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

#include "controllerMmio.h"

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

controllerMmio_c::controllerMmio_c(void)
{
}

controllerMmio_c::~controllerMmio_c(void)    
{	
}

controllerMmio_c& controllerMmio_c::getInstance(void)
{
    static controllerMmio_c mInstance;
    return mInstance;
}


cap_t controllerMmio_c::getControllerCapabilities(uio_c& uioDrv) const     
{
    cap_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cap_t), CONTROLLER_REG_OFFSET_CAP);
    return shadowReg;
}

vs_t controllerMmio_c::getVersion(uio_c& uioDrv) const
{
    vs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(vs_t), CONTROLLER_REG_OFFSET_VS);
    return shadowReg;
}

intms_t controllerMmio_c::getInterruptMaskSet(uio_c& uioDrv) const
{
    intms_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(intms_t), CONTROLLER_REG_OFFSET_INTMS);
    return shadowReg;
}

intmc_t controllerMmio_c::getInterruptMaskClear(uio_c& uioDrv) const
{
    intmc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(intmc_t), CONTROLLER_REG_OFFSET_INTMC);
    return shadowReg;
}

cc_t controllerMmio_c::getControllerConfiguration(uio_c& uioDrv) const
{
    cc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cc_t), CONTROLLER_REG_OFFSET_CC);
    return shadowReg;
}

csts_t controllerMmio_c::getControllerStatus(uio_c& uioDrv) const
{
    csts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(csts_t), CONTROLLER_REG_OFFSET_CSTS);
    return shadowReg;
}

nssr_t controllerMmio_c::getNvmSubsystemReset(uio_c& uioDrv) const
{
    nssr_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(nssr_t), CONTROLLER_REG_OFFSET_NSSR);
    return shadowReg;
}

aqa_t controllerMmio_c::getAdminQueueAttributes(uio_c& uioDrv) const
{
    aqa_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(aqa_t), CONTROLLER_REG_OFFSET_AQA);
    return shadowReg;
}

asq_t controllerMmio_c::getAdminSubmissionQueueBaseAddress(uio_c& uioDrv) const
{
    asq_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(asq_t), CONTROLLER_REG_OFFSET_ASQ);
    return shadowReg;
}

acq_t controllerMmio_c::getAdminCompletionQueueBaseAddress(uio_c& uioDrv) const
{
    acq_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(acq_t), CONTROLLER_REG_OFFSET_ACQ);
    return shadowReg;
}

cmbloc_t controllerMmio_c::getControllerMemoryBufferLocation(uio_c& uioDrv) const
{
    cmbloc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbloc_t), CONTROLLER_REG_OFFSET_CMBLOC);
    return shadowReg;
}

cmbsz_t controllerMmio_c::getControllerMemoryBufferSize(uio_c& uioDrv) const
{
    cmbsz_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbsz_t), CONTROLLER_REG_OFFSET_CMBSZ);
    return shadowReg;
}

bpinfo_t controllerMmio_c::getBootParitionInformation(uio_c& uioDrv) const
{
    bpinfo_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bpinfo_t), CONTROLLER_REG_OFFSET_BPINFO);
    return shadowReg;
}

bprsel_t controllerMmio_c::getBootParitionReadSelect(uio_c& uioDrv) const
{
    bprsel_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bprsel_t), CONTROLLER_REG_OFFSET_BPRSEL);
    return shadowReg;
}

bpmbl_t controllerMmio_c::getBootParitionMemoryBufferLocation(uio_c& uioDrv) const
{
    bpmbl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bpmbl_t), CONTROLLER_REG_OFFSET_BPMBL);
    return shadowReg;
}

cmbmsc_t controllerMmio_c::getControllerMemoryBufferMemorySpaceControl(uio_c& uioDrv) const
{
    cmbmsc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbmsc_t), CONTROLLER_REG_OFFSET_CMBMSC);
    return shadowReg;
}

cmbsts_t controllerMmio_c::getControllerMemoryBufferStatus(uio_c& uioDrv) const
{
    cmbsts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbsts_t), CONTROLLER_REG_OFFSET_CMBSTS);
    return shadowReg;
}

cmbebs_t controllerMmio_c::getControllerMemoryBufferElasticityBufferSize(uio_c& uioDrv) const
{
    cmbebs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbebs_t), CONTROLLER_REG_OFFSET_CMBEBS);
    return shadowReg;
}

cmbswtp_t controllerMmio_c::getControllerMemoryBufferSustainedWriteThroughput(uio_c& uioDrv) const
{
    cmbswtp_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbswtp_t), CONTROLLER_REG_OFFSET_CMBSWTP);
    return shadowReg;
}

nssd_t controllerMmio_c::getNvmSubsystemShutdown(uio_c& uioDrv) const
{
    nssd_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(nssd_t), CONTROLLER_REG_OFFSET_NSSD);
    return shadowReg;
}

crto_t controllerMmio_c::getControllerReadyTimeout(uio_c& uioDrv) const
{
    crto_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(crto_t), CONTROLLER_REG_OFFSET_CRTO);
    return shadowReg;
}

pmrcap_t controllerMmio_c::getPersistentMemoryCapabilities(uio_c& uioDrv) const
{
    pmrcap_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrcap_t), CONTROLLER_REG_OFFSET_PMRCAP);
    return shadowReg;
}

pmrctl_t controllerMmio_c::getPersistentMemoryRegionControl(uio_c& uioDrv) const
{
    pmrctl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrctl_t), CONTROLLER_REG_OFFSET_PMRCTL);
    return shadowReg;
}

pmrsts_t controllerMmio_c::getPersistentMemoryRegionStatus(uio_c& uioDrv) const
{
    pmrsts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrsts_t), CONTROLLER_REG_OFFSET_PMRSTS);
    return shadowReg;
}

pmrebs_t controllerMmio_c::getPersistentMemoryRegionElasticityBufferSize(uio_c& uioDrv) const
{
    pmrebs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrebs_t), CONTROLLER_REG_OFFSET_PMREBS);
    return shadowReg;
}

pmrswtp_t controllerMmio_c::getPersistentMemorySustainedWriteThroughput(uio_c& uioDrv) const
{
    pmrswtp_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrswtp_t), CONTROLLER_REG_OFFSET_PMRSWTP);
    return shadowReg;
}

pmrmscl_t controllerMmio_c::getPersistentMemoryRegionControllerMemorySpaceControlLower(uio_c& uioDrv) const
{
    pmrmscl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrmscl_t), CONTROLLER_REG_OFFSET_PMRMSCL);
    return shadowReg;
}

pmrmscu_t controllerMmio_c::getPersistentMemoryRegionControllerMemorySpaceControlUpper(uio_c& uioDrv) const
{
    pmrmscu_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrmscu_t), CONTROLLER_REG_OFFSET_PMRMSCU);
    return shadowReg;
}

void controllerMmio_c::setControllerCapabilities(uio_c& uioDrv, cap_t cap) const
{
    pwrite(uioDrv.mUioResource0_fd, &cap, sizeof(cap_t), CONTROLLER_REG_OFFSET_CAP);
}

void controllerMmio_c::setVersion(uio_c& uioDrv, vs_t vs) const
{
    pwrite(uioDrv.mUioResource0_fd, &vs, sizeof(vs_t), CONTROLLER_REG_OFFSET_VS);
}

void controllerMmio_c::setInterruptMaskSet(uio_c& uioDrv, intms_t intms) const
{
    pwrite(uioDrv.mUioResource0_fd, &intms, sizeof(intms_t), CONTROLLER_REG_OFFSET_INTMS);
}

void controllerMmio_c::setInterruptMaskClear(uio_c& uioDrv, intmc_t intmc) const
{
    pwrite(uioDrv.mUioResource0_fd, &intmc, sizeof(intmc_t), CONTROLLER_REG_OFFSET_INTMC);
}

void controllerMmio_c::setControllerConfiguration(uio_c& uioDrv, cc_t cc) const
{
    pwrite(uioDrv.mUioResource0_fd, &cc, sizeof(cc_t), CONTROLLER_REG_OFFSET_CC);
}

void controllerMmio_c::setControllerStatus(uio_c& uioDrv, csts_t csts) const
{
    pwrite(uioDrv.mUioResource0_fd, &csts, sizeof(csts_t), CONTROLLER_REG_OFFSET_CSTS);
}

void controllerMmio_c::setNvmSubsystemReset(uio_c& uioDrv, nssr_t nssr) const
{
    pwrite(uioDrv.mUioResource0_fd, &nssr, sizeof(nssr_t), CONTROLLER_REG_OFFSET_NSSR);
}

void controllerMmio_c::setAdminQueueAttributes(uio_c& uioDrv, aqa_t aqa) const
{
    pwrite(uioDrv.mUioResource0_fd, &aqa, sizeof(aqa_t), CONTROLLER_REG_OFFSET_AQA);
}

void controllerMmio_c::setAdminSubmissionQueueBaseAddress(uio_c& uioDrv, asq_t asq) const
{
    pwrite(uioDrv.mUioResource0_fd, &asq, sizeof(asq_t), CONTROLLER_REG_OFFSET_ASQ);
}

void controllerMmio_c::setAdminCompletionQueueBaseAddress(uio_c& uioDrv, acq_t acq) const
{
    pwrite(uioDrv.mUioResource0_fd, &acq, sizeof(acq_t), CONTROLLER_REG_OFFSET_ACQ);
}

void controllerMmio_c::setControllerMemoryBufferLocation(uio_c& uioDrv, cmbloc_t cmbloc) const
{
    pwrite(uioDrv.mUioResource0_fd, &cmbloc, sizeof(cmbloc_t), CONTROLLER_REG_OFFSET_CMBLOC);
}

void controllerMmio_c::setControllerMemoryBufferSize(uio_c& uioDrv, cmbsz_t cmbsz) const
{
    pwrite(uioDrv.mUioResource0_fd, &cmbsz, sizeof(cmbsz_t), CONTROLLER_REG_OFFSET_CMBSZ);
}

void controllerMmio_c::setBootParitionInformation(uio_c& uioDrv, bpinfo_t bpinfo) const
{
    pwrite(uioDrv.mUioResource0_fd, &bpinfo, sizeof(bpinfo_t), CONTROLLER_REG_OFFSET_BPINFO);
}

void controllerMmio_c::setBootParitionReadSelect(uio_c& uioDrv, bprsel_t bprsel) const
{
    pwrite(uioDrv.mUioResource0_fd, &bprsel, sizeof(bprsel_t), CONTROLLER_REG_OFFSET_BPRSEL);
}

void controllerMmio_c::setBootParitionMemoryBufferLocation(uio_c& uioDrv, bpmbl_t bpmbl) const
{
    pwrite(uioDrv.mUioResource0_fd, &bpmbl, sizeof(bpmbl_t), CONTROLLER_REG_OFFSET_BPMBL);
}

void controllerMmio_c::setControllerMemoryBufferMemorySpaceControl(uio_c& uioDrv, cmbmsc_t cmbmsc) const
{
    pwrite(uioDrv.mUioResource0_fd, &cmbmsc, sizeof(cmbmsc_t), CONTROLLER_REG_OFFSET_CMBMSC);
}

void controllerMmio_c::setControllerMemoryBufferStatus(uio_c& uioDrv, cmbsts_t cmbsts) const
{
    pwrite(uioDrv.mUioResource0_fd, &cmbsts, sizeof(cmbsts_t), CONTROLLER_REG_OFFSET_CMBSTS);
}

void controllerMmio_c::setControllerMemoryBufferElasticityBufferSize(uio_c& uioDrv, cmbebs_t cmbebs) const
{
    pwrite(uioDrv.mUioResource0_fd, &cmbebs, sizeof(cmbebs_t), CONTROLLER_REG_OFFSET_CMBEBS);
}

void controllerMmio_c::setControllerMemoryBufferSustainedWriteThroughput(uio_c& uioDrv, cmbswtp_t cmbswtp) const
{
    pwrite(uioDrv.mUioResource0_fd, &cmbswtp, sizeof(cmbswtp_t), CONTROLLER_REG_OFFSET_CMBSWTP);
}

void controllerMmio_c::setNvmSubsystemShutdown(uio_c& uioDrv, nssd_t nssd) const
{
    pwrite(uioDrv.mUioResource0_fd, &nssd, sizeof(nssd_t), CONTROLLER_REG_OFFSET_NSSD);
}

void controllerMmio_c::setControllerReadyTimeout(uio_c& uioDrv, crto_t crto) const
{
    pwrite(uioDrv.mUioResource0_fd, &crto, sizeof(crto_t), CONTROLLER_REG_OFFSET_CRTO);
}

void controllerMmio_c::setPersistentMemoryCapabilities(uio_c& uioDrv, pmrcap_t pmrcap) const
{
    pwrite(uioDrv.mUioResource0_fd, &pmrcap, sizeof(pmrcap_t), CONTROLLER_REG_OFFSET_PMRCAP);
}

void controllerMmio_c::setPersistentMemoryRegionControl(uio_c& uioDrv, pmrctl_t pmrctl) const
{
    pwrite(uioDrv.mUioResource0_fd, &pmrctl, sizeof(pmrctl_t), CONTROLLER_REG_OFFSET_PMRCTL);
}

void controllerMmio_c::setPersistentMemoryRegionStatus(uio_c& uioDrv, pmrsts_t pmrsts) const
{
    pwrite(uioDrv.mUioResource0_fd, &pmrsts, sizeof(pmrsts_t), CONTROLLER_REG_OFFSET_PMRSTS);
}

void controllerMmio_c::setPersistentMemoryRegionElasticityBufferSize(uio_c& uioDrv, pmrebs_t pmrebs) const
{
    pwrite(uioDrv.mUioResource0_fd, &pmrebs, sizeof(pmrebs_t), CONTROLLER_REG_OFFSET_PMREBS);
}

void controllerMmio_c::setPersistentMemorySustainedWriteThroughput(uio_c& uioDrv, pmrswtp_t pmrswtp) const
{
    pwrite(uioDrv.mUioResource0_fd, &pmrswtp, sizeof(pmrswtp_t), CONTROLLER_REG_OFFSET_PMRSWTP);
}

void controllerMmio_c::setPersistentMemoryRegionControllerMemorySpaceControlLower(uio_c& uioDrv, pmrmscl_t pmrmscl) const
{
    pwrite(uioDrv.mUioResource0_fd, &pmrmscl, sizeof(pmrmscl_t), CONTROLLER_REG_OFFSET_PMRMSCL);
}

void controllerMmio_c::setPersistentMemoryRegionControllerMemorySpaceControlUpper(uio_c& uioDrv, pmrmscu_t pmrmscu) const
{
    pwrite(uioDrv.mUioResource0_fd, &pmrmscu, sizeof(pmrmscu_t), CONTROLLER_REG_OFFSET_PMRMSCU);
}

