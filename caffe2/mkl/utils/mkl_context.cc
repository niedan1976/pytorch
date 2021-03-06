// #include "caffe2/mkl/utils/mkl_context.h"

#include "mkl_context.h"
#include "caffe2/core/event_cpu.h"

namespace caffe2 {

// MKL events are the same as CPU events

REGISTER_EVENT_CREATE_FUNCTION(MKLDNN, EventCreateCPU);
REGISTER_EVENT_RECORD_FUNCTION(MKLDNN, EventRecordCPU);
REGISTER_EVENT_WAIT_FUNCTION(MKLDNN, MKLDNN, EventWaitCPUCPU);
REGISTER_EVENT_WAIT_FUNCTION(MKLDNN, CPU, EventWaitCPUCPU);
REGISTER_EVENT_WAIT_FUNCTION(CPU, MKLDNN, EventWaitCPUCPU);
REGISTER_EVENT_FINISH_FUNCTION(MKLDNN, EventFinishCPU);

REGISTER_EVENT_QUERY_FUNCTION(MKLDNN, EventQueryCPU);
REGISTER_EVENT_ERROR_MESSAGE_FUNCTION(MKLDNN, EventErrorMessageCPU);
REGISTER_EVENT_SET_FINISHED_FUNCTION(MKLDNN, EventSetFinishedCPU);
REGISTER_EVENT_RESET_FUNCTION(MKLDNN, EventResetCPU);

BaseStaticContext* GetMKLStaticContext() {
  static MKLStaticContext context;
  return &context;
}

REGISTER_STATIC_CONTEXT(MKLDNN, GetMKLStaticContext());

} // namespace caffe2
