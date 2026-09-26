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

controllerMmio_c::controllerMmio_c()
{
}

controllerMmio_c::~controllerMmio_c()    
{	
}

controllerMmio_c& controllerMmio_c::getInstance()
{
    static controllerMmio_c mInstance;
    return mInstance;
}


cap_t controllerMmio_c::getControllerCapabilities(int uioId) const     
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cap_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cap_t), CONTROLLER_REG_OFFSET_CAP);
    return shadowReg;
}

vs_t controllerMmio_c::getVersion(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    vs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(vs_t), CONTROLLER_REG_OFFSET_VS);
    return shadowReg;
}

intms_t controllerMmio_c::getInterruptMaskSet(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    intms_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(intms_t), CONTROLLER_REG_OFFSET_INTMS);
    return shadowReg;
}

intmc_t controllerMmio_c::getInterruptMaskClear(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    intmc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(intmc_t), CONTROLLER_REG_OFFSET_INTMC);
    return shadowReg;
}

cc_t controllerMmio_c::getControllerConfiguration(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cc_t), CONTROLLER_REG_OFFSET_CC);
    return shadowReg;
}

csts_t controllerMmio_c::getControllerStatus(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    csts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(csts_t), CONTROLLER_REG_OFFSET_CSTS);
    return shadowReg;
}

nssr_t controllerMmio_c::getNvmSubsystemReset(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    nssr_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(nssr_t), CONTROLLER_REG_OFFSET_NSSR);
    return shadowReg;
}

aqa_t controllerMmio_c::getAdminQueueAttributes(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    aqa_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(aqa_t), CONTROLLER_REG_OFFSET_AQA);
    return shadowReg;
}

asq_t controllerMmio_c::getAdminSubmissionQueueBaseAddress(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    asq_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(asq_t), CONTROLLER_REG_OFFSET_ASQ);
    return shadowReg;
}

acq_t controllerMmio_c::getAdminCompletionQueueBaseAddress(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    acq_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(acq_t), CONTROLLER_REG_OFFSET_ACQ);
    return shadowReg;
}

cmbloc_t controllerMmio_c::getControllerMemoryBufferLocation(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);    
    cmbloc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbloc_t), CONTROLLER_REG_OFFSET_CMBLOC);
    return shadowReg;
}

cmbsz_t controllerMmio_c::getControllerMemoryBufferSize(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cmbsz_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbsz_t), CONTROLLER_REG_OFFSET_CMBSZ);
    return shadowReg;
}

bpinfo_t controllerMmio_c::getBootParitionInformation(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    bpinfo_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bpinfo_t), CONTROLLER_REG_OFFSET_BPINFO);
    return shadowReg;
}

bprsel_t controllerMmio_c::getBootParitionReadSelect(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    bprsel_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bprsel_t), CONTROLLER_REG_OFFSET_BPRSEL);
    return shadowReg;
}

bpmbl_t controllerMmio_c::getBootParitionMemoryBufferLocation(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    bpmbl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(bpmbl_t), CONTROLLER_REG_OFFSET_BPMBL);
    return shadowReg;
}

cmbmsc_t controllerMmio_c::getControllerMemoryBufferMemorySpaceControl(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cmbmsc_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbmsc_t), CONTROLLER_REG_OFFSET_CMBMSC);
    return shadowReg;
}

cmbsts_t controllerMmio_c::getControllerMemoryBufferStatus(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cmbsts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbsts_t), CONTROLLER_REG_OFFSET_CMBSTS);
    return shadowReg;
}

cmbebs_t controllerMmio_c::getControllerMemoryBufferElasticityBufferSize(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cmbebs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbebs_t), CONTROLLER_REG_OFFSET_CMBEBS);
    return shadowReg;
}

cmbswtp_t controllerMmio_c::getControllerMemoryBufferSustainedWriteThroughput(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cmbswtp_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cmbswtp_t), CONTROLLER_REG_OFFSET_CMBSWTP);
    return shadowReg;
}

nssd_t controllerMmio_c::getNvmSubsystemShutdown(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    nssd_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(nssd_t), CONTROLLER_REG_OFFSET_NSSD);
    return shadowReg;
}

crto_t controllerMmio_c::getControllerReadyTimeout(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    crto_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(crto_t), CONTROLLER_REG_OFFSET_CRTO);
    return shadowReg;
}

pmrcap_t controllerMmio_c::getPersistentMemoryCapabilities(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pmrcap_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrcap_t), CONTROLLER_REG_OFFSET_PMRCAP);
    return shadowReg;
}

pmrctl_t controllerMmio_c::getPersistentMemoryRegionControl(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pmrctl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrctl_t), CONTROLLER_REG_OFFSET_PMRCTL);
    return shadowReg;
}

pmrsts_t controllerMmio_c::getPersistentMemoryRegionStatus(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pmrsts_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrsts_t), CONTROLLER_REG_OFFSET_PMRSTS);
    return shadowReg;
}

pmrebs_t controllerMmio_c::getPersistentMemoryRegionElasticityBufferSize(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pmrebs_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrebs_t), CONTROLLER_REG_OFFSET_PMREBS);
    return shadowReg;
}

pmrswtp_t controllerMmio_c::getPersistentMemorySustainedWriteThroughput(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pmrswtp_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrswtp_t), CONTROLLER_REG_OFFSET_PMRSWTP);
    return shadowReg;
}

pmrmscl_t controllerMmio_c::getPersistentMemoryRegionControllerMemorySpaceControlLower(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pmrmscl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrmscl_t), CONTROLLER_REG_OFFSET_PMRMSCL);
    return shadowReg;
}

pmrmscu_t controllerMmio_c::getPersistentMemoryRegionControllerMemorySpaceControlUpper(int uioId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pmrmscu_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(pmrmscu_t), CONTROLLER_REG_OFFSET_PMRMSCU);
    return shadowReg;
}


void controllerMmio_c::setControllerCapabilities(int uioId, cap_t cap) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &cap, sizeof(cap_t), CONTROLLER_REG_OFFSET_CAP);
}

void controllerMmio_c::setVersion(int uioId, vs_t vs) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &vs, sizeof(vs_t), CONTROLLER_REG_OFFSET_VS);
}

void controllerMmio_c::setInterruptMaskSet(int uioId, intms_t intms) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &intms, sizeof(intms_t), CONTROLLER_REG_OFFSET_INTMS);
}

void controllerMmio_c::setInterruptMaskClear(int uioId, intmc_t intmc) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &intmc, sizeof(intmc_t), CONTROLLER_REG_OFFSET_INTMC);
}

void controllerMmio_c::setControllerConfiguration(int uioId, cc_t cc) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &cc, sizeof(cc_t), CONTROLLER_REG_OFFSET_CC);
}

void controllerMmio_c::setControllerStatus(int uioId, csts_t csts) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &csts, sizeof(csts_t), CONTROLLER_REG_OFFSET_CSTS);
}

void controllerMmio_c::setNvmSubsystemReset(int uioId, nssr_t nssr) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &nssr, sizeof(nssr_t), CONTROLLER_REG_OFFSET_NSSR);
}

void controllerMmio_c::setAdminQueueAttributes(int uioId, aqa_t aqa) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &aqa, sizeof(aqa_t), CONTROLLER_REG_OFFSET_AQA);
}

void controllerMmio_c::setAdminSubmissionQueueBaseAddress(int uioId, asq_t asq) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &asq, sizeof(asq_t), CONTROLLER_REG_OFFSET_ASQ);
}

void controllerMmio_c::setAdminCompletionQueueBaseAddress(int uioId, acq_t acq) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &acq, sizeof(acq_t), CONTROLLER_REG_OFFSET_ACQ);
}

void controllerMmio_c::setControllerMemoryBufferLocation(int uioId, cmbloc_t cmbloc) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &cmbloc, sizeof(cmbloc_t), CONTROLLER_REG_OFFSET_CMBLOC);
}

void controllerMmio_c::setControllerMemoryBufferSize(int uioId, cmbsz_t cmbsz) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &cmbsz, sizeof(cmbsz_t), CONTROLLER_REG_OFFSET_CMBSZ);
}

void controllerMmio_c::setBootParitionInformation(int uioId, bpinfo_t bpinfo) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &bpinfo, sizeof(bpinfo_t), CONTROLLER_REG_OFFSET_BPINFO);
}

void controllerMmio_c::setBootParitionReadSelect(int uioId, bprsel_t bprsel) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &bprsel, sizeof(bprsel_t), CONTROLLER_REG_OFFSET_BPRSEL);
}

void controllerMmio_c::setBootParitionMemoryBufferLocation(int uioId, bpmbl_t bpmbl) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &bpmbl, sizeof(bpmbl_t), CONTROLLER_REG_OFFSET_BPMBL);
}

void controllerMmio_c::setControllerMemoryBufferMemorySpaceControl(int uioId, cmbmsc_t cmbmsc) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &cmbmsc, sizeof(cmbmsc_t), CONTROLLER_REG_OFFSET_CMBMSC);
}

void controllerMmio_c::setControllerMemoryBufferStatus(int uioId, cmbsts_t cmbsts) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &cmbsts, sizeof(cmbsts_t), CONTROLLER_REG_OFFSET_CMBSTS);
}

void controllerMmio_c::setControllerMemoryBufferElasticityBufferSize(int uioId, cmbebs_t cmbebs) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &cmbebs, sizeof(cmbebs_t), CONTROLLER_REG_OFFSET_CMBEBS);
}

void controllerMmio_c::setControllerMemoryBufferSustainedWriteThroughput(int uioId, cmbswtp_t cmbswtp) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &cmbswtp, sizeof(cmbswtp_t), CONTROLLER_REG_OFFSET_CMBSWTP);
}

void controllerMmio_c::setNvmSubsystemShutdown(int uioId, nssd_t nssd) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &nssd, sizeof(nssd_t), CONTROLLER_REG_OFFSET_NSSD);
}

void controllerMmio_c::setControllerReadyTimeout(int uioId, crto_t crto) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &crto, sizeof(crto_t), CONTROLLER_REG_OFFSET_CRTO);
}

void controllerMmio_c::setPersistentMemoryCapabilities(int uioId, pmrcap_t pmrcap) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &pmrcap, sizeof(pmrcap_t), CONTROLLER_REG_OFFSET_PMRCAP);
}

void controllerMmio_c::setPersistentMemoryRegionControl(int uioId, pmrctl_t pmrctl) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &pmrctl, sizeof(pmrctl_t), CONTROLLER_REG_OFFSET_PMRCTL);
}

void controllerMmio_c::setPersistentMemoryRegionStatus(int uioId, pmrsts_t pmrsts) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &pmrsts, sizeof(pmrsts_t), CONTROLLER_REG_OFFSET_PMRSTS);
}

void controllerMmio_c::setPersistentMemoryRegionElasticityBufferSize(int uioId, pmrebs_t pmrebs) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &pmrebs, sizeof(pmrebs_t), CONTROLLER_REG_OFFSET_PMREBS);
}

void controllerMmio_c::setPersistentMemorySustainedWriteThroughput(int uioId, pmrswtp_t pmrswtp) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &pmrswtp, sizeof(pmrswtp_t), CONTROLLER_REG_OFFSET_PMRSWTP);
}

void controllerMmio_c::setPersistentMemoryRegionControllerMemorySpaceControlLower(int uioId, pmrmscl_t pmrmscl) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &pmrmscl, sizeof(pmrmscl_t), CONTROLLER_REG_OFFSET_PMRMSCL);
}

void controllerMmio_c::setPersistentMemoryRegionControllerMemorySpaceControlUpper(int uioId, pmrmscu_t pmrmscu) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    pwrite(uioDrv.mUioResource0_fd, &pmrmscu, sizeof(pmrmscu_t), CONTROLLER_REG_OFFSET_PMRMSCU);
}


uint16_t controllerMmio_c::getSqTailDoorbell(int uioId, uint32_t sqId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    sqtdbl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(sqtdbl_t), CONTROLLER_REG_SQT_CQH_STARTING_OFFSET + sqId * 8);
    return shadowReg.SQT;
}

uint16_t controllerMmio_c::getCqHeadDoorbell(int uioId, uint32_t cqId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cqhdbl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cqhdbl_t), CONTROLLER_REG_SQT_CQH_STARTING_OFFSET + cqId * 8);
    return shadowReg.CQH;
}

void controllerMmio_c::setSqTailDoorbell(int uioId, uint32_t sqId, uint16_t value) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    sqtdbl_t shadowReg;
    shadowReg.SQT = value;
    pwrite(uioDrv.mUioResource0_fd, &shadowReg, sizeof(sqtdbl_t), CONTROLLER_REG_SQT_CQH_STARTING_OFFSET + sqId * 8);
}

void controllerMmio_c::setCqHeadDoorbell(int uioId, uint32_t cqId, uint16_t value) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cqhdbl_t shadowReg;
    shadowReg.CQH = value;
    pwrite(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cqhdbl_t), CONTROLLER_REG_SQT_CQH_STARTING_OFFSET + cqId * 8);
}

void controllerMmio_c::incrementSqTailDoorbell(int uioId, uint32_t sqId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    sqtdbl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(sqtdbl_t), CONTROLLER_REG_SQT_CQH_STARTING_OFFSET + sqId * 8);
    if (shadowReg.SQT == 0xFFFF)
    {
        shadowReg.SQT = 0;
    }
    else
    {
        shadowReg.SQT++;
    }
    pwrite(uioDrv.mUioResource0_fd, &shadowReg, sizeof(sqtdbl_t), CONTROLLER_REG_SQT_CQH_STARTING_OFFSET + sqId * 8);
}

void controllerMmio_c::incrementCqHeadDoorbell(int uioId, uint32_t cqId) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    cqhdbl_t shadowReg;
    pread(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cqhdbl_t), CONTROLLER_REG_SQT_CQH_STARTING_OFFSET + cqId * 8);
    if (shadowReg.CQH == 0xFFFF)
    {
        shadowReg.CQH = 0;
    }
    else
    {
        shadowReg.CQH++;
    }
    pwrite(uioDrv.mUioResource0_fd, &shadowReg, sizeof(cqhdbl_t), CONTROLLER_REG_SQT_CQH_STARTING_OFFSET + cqId * 8);
}