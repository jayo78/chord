/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: chord.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "chord.pb-c.h"
void   protocol__node__init
                     (Protocol__Node         *message)
{
  static const Protocol__Node init_value = PROTOCOL__NODE__INIT;
  *message = init_value;
}
size_t protocol__node__get_packed_size
                     (const Protocol__Node *message)
{
  assert(message->base.descriptor == &protocol__node__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__node__pack
                     (const Protocol__Node *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__node__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__node__pack_to_buffer
                     (const Protocol__Node *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__node__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__Node *
       protocol__node__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__Node *)
     protobuf_c_message_unpack (&protocol__node__descriptor,
                                allocator, len, data);
}
void   protocol__node__free_unpacked
                     (Protocol__Node *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__node__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__call__init
                     (Protocol__Call         *message)
{
  static const Protocol__Call init_value = PROTOCOL__CALL__INIT;
  *message = init_value;
}
size_t protocol__call__get_packed_size
                     (const Protocol__Call *message)
{
  assert(message->base.descriptor == &protocol__call__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__call__pack
                     (const Protocol__Call *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__call__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__call__pack_to_buffer
                     (const Protocol__Call *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__call__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__Call *
       protocol__call__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__Call *)
     protobuf_c_message_unpack (&protocol__call__descriptor,
                                allocator, len, data);
}
void   protocol__call__free_unpacked
                     (Protocol__Call *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__call__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__return__init
                     (Protocol__Return         *message)
{
  static const Protocol__Return init_value = PROTOCOL__RETURN__INIT;
  *message = init_value;
}
size_t protocol__return__get_packed_size
                     (const Protocol__Return *message)
{
  assert(message->base.descriptor == &protocol__return__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__return__pack
                     (const Protocol__Return *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__return__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__return__pack_to_buffer
                     (const Protocol__Return *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__return__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__Return *
       protocol__return__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__Return *)
     protobuf_c_message_unpack (&protocol__return__descriptor,
                                allocator, len, data);
}
void   protocol__return__free_unpacked
                     (Protocol__Return *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__return__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__find_successor_args__init
                     (Protocol__FindSuccessorArgs         *message)
{
  static const Protocol__FindSuccessorArgs init_value = PROTOCOL__FIND_SUCCESSOR_ARGS__INIT;
  *message = init_value;
}
size_t protocol__find_successor_args__get_packed_size
                     (const Protocol__FindSuccessorArgs *message)
{
  assert(message->base.descriptor == &protocol__find_successor_args__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__find_successor_args__pack
                     (const Protocol__FindSuccessorArgs *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__find_successor_args__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__find_successor_args__pack_to_buffer
                     (const Protocol__FindSuccessorArgs *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__find_successor_args__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__FindSuccessorArgs *
       protocol__find_successor_args__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__FindSuccessorArgs *)
     protobuf_c_message_unpack (&protocol__find_successor_args__descriptor,
                                allocator, len, data);
}
void   protocol__find_successor_args__free_unpacked
                     (Protocol__FindSuccessorArgs *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__find_successor_args__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__find_successor_ret__init
                     (Protocol__FindSuccessorRet         *message)
{
  static const Protocol__FindSuccessorRet init_value = PROTOCOL__FIND_SUCCESSOR_RET__INIT;
  *message = init_value;
}
size_t protocol__find_successor_ret__get_packed_size
                     (const Protocol__FindSuccessorRet *message)
{
  assert(message->base.descriptor == &protocol__find_successor_ret__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__find_successor_ret__pack
                     (const Protocol__FindSuccessorRet *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__find_successor_ret__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__find_successor_ret__pack_to_buffer
                     (const Protocol__FindSuccessorRet *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__find_successor_ret__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__FindSuccessorRet *
       protocol__find_successor_ret__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__FindSuccessorRet *)
     protobuf_c_message_unpack (&protocol__find_successor_ret__descriptor,
                                allocator, len, data);
}
void   protocol__find_successor_ret__free_unpacked
                     (Protocol__FindSuccessorRet *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__find_successor_ret__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__notify_args__init
                     (Protocol__NotifyArgs         *message)
{
  static const Protocol__NotifyArgs init_value = PROTOCOL__NOTIFY_ARGS__INIT;
  *message = init_value;
}
size_t protocol__notify_args__get_packed_size
                     (const Protocol__NotifyArgs *message)
{
  assert(message->base.descriptor == &protocol__notify_args__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__notify_args__pack
                     (const Protocol__NotifyArgs *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__notify_args__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__notify_args__pack_to_buffer
                     (const Protocol__NotifyArgs *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__notify_args__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__NotifyArgs *
       protocol__notify_args__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__NotifyArgs *)
     protobuf_c_message_unpack (&protocol__notify_args__descriptor,
                                allocator, len, data);
}
void   protocol__notify_args__free_unpacked
                     (Protocol__NotifyArgs *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__notify_args__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__notify_ret__init
                     (Protocol__NotifyRet         *message)
{
  static const Protocol__NotifyRet init_value = PROTOCOL__NOTIFY_RET__INIT;
  *message = init_value;
}
size_t protocol__notify_ret__get_packed_size
                     (const Protocol__NotifyRet *message)
{
  assert(message->base.descriptor == &protocol__notify_ret__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__notify_ret__pack
                     (const Protocol__NotifyRet *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__notify_ret__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__notify_ret__pack_to_buffer
                     (const Protocol__NotifyRet *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__notify_ret__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__NotifyRet *
       protocol__notify_ret__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__NotifyRet *)
     protobuf_c_message_unpack (&protocol__notify_ret__descriptor,
                                allocator, len, data);
}
void   protocol__notify_ret__free_unpacked
                     (Protocol__NotifyRet *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__notify_ret__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__check_predecessor_args__init
                     (Protocol__CheckPredecessorArgs         *message)
{
  static const Protocol__CheckPredecessorArgs init_value = PROTOCOL__CHECK_PREDECESSOR_ARGS__INIT;
  *message = init_value;
}
size_t protocol__check_predecessor_args__get_packed_size
                     (const Protocol__CheckPredecessorArgs *message)
{
  assert(message->base.descriptor == &protocol__check_predecessor_args__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__check_predecessor_args__pack
                     (const Protocol__CheckPredecessorArgs *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__check_predecessor_args__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__check_predecessor_args__pack_to_buffer
                     (const Protocol__CheckPredecessorArgs *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__check_predecessor_args__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__CheckPredecessorArgs *
       protocol__check_predecessor_args__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__CheckPredecessorArgs *)
     protobuf_c_message_unpack (&protocol__check_predecessor_args__descriptor,
                                allocator, len, data);
}
void   protocol__check_predecessor_args__free_unpacked
                     (Protocol__CheckPredecessorArgs *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__check_predecessor_args__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__check_predecessor_ret__init
                     (Protocol__CheckPredecessorRet         *message)
{
  static const Protocol__CheckPredecessorRet init_value = PROTOCOL__CHECK_PREDECESSOR_RET__INIT;
  *message = init_value;
}
size_t protocol__check_predecessor_ret__get_packed_size
                     (const Protocol__CheckPredecessorRet *message)
{
  assert(message->base.descriptor == &protocol__check_predecessor_ret__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__check_predecessor_ret__pack
                     (const Protocol__CheckPredecessorRet *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__check_predecessor_ret__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__check_predecessor_ret__pack_to_buffer
                     (const Protocol__CheckPredecessorRet *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__check_predecessor_ret__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__CheckPredecessorRet *
       protocol__check_predecessor_ret__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__CheckPredecessorRet *)
     protobuf_c_message_unpack (&protocol__check_predecessor_ret__descriptor,
                                allocator, len, data);
}
void   protocol__check_predecessor_ret__free_unpacked
                     (Protocol__CheckPredecessorRet *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__check_predecessor_ret__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__get_predecessor_args__init
                     (Protocol__GetPredecessorArgs         *message)
{
  static const Protocol__GetPredecessorArgs init_value = PROTOCOL__GET_PREDECESSOR_ARGS__INIT;
  *message = init_value;
}
size_t protocol__get_predecessor_args__get_packed_size
                     (const Protocol__GetPredecessorArgs *message)
{
  assert(message->base.descriptor == &protocol__get_predecessor_args__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__get_predecessor_args__pack
                     (const Protocol__GetPredecessorArgs *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__get_predecessor_args__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__get_predecessor_args__pack_to_buffer
                     (const Protocol__GetPredecessorArgs *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__get_predecessor_args__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__GetPredecessorArgs *
       protocol__get_predecessor_args__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__GetPredecessorArgs *)
     protobuf_c_message_unpack (&protocol__get_predecessor_args__descriptor,
                                allocator, len, data);
}
void   protocol__get_predecessor_args__free_unpacked
                     (Protocol__GetPredecessorArgs *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__get_predecessor_args__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__get_predecessor_ret__init
                     (Protocol__GetPredecessorRet         *message)
{
  static const Protocol__GetPredecessorRet init_value = PROTOCOL__GET_PREDECESSOR_RET__INIT;
  *message = init_value;
}
size_t protocol__get_predecessor_ret__get_packed_size
                     (const Protocol__GetPredecessorRet *message)
{
  assert(message->base.descriptor == &protocol__get_predecessor_ret__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__get_predecessor_ret__pack
                     (const Protocol__GetPredecessorRet *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__get_predecessor_ret__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__get_predecessor_ret__pack_to_buffer
                     (const Protocol__GetPredecessorRet *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__get_predecessor_ret__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__GetPredecessorRet *
       protocol__get_predecessor_ret__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__GetPredecessorRet *)
     protobuf_c_message_unpack (&protocol__get_predecessor_ret__descriptor,
                                allocator, len, data);
}
void   protocol__get_predecessor_ret__free_unpacked
                     (Protocol__GetPredecessorRet *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__get_predecessor_ret__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__get_successor_list_args__init
                     (Protocol__GetSuccessorListArgs         *message)
{
  static const Protocol__GetSuccessorListArgs init_value = PROTOCOL__GET_SUCCESSOR_LIST_ARGS__INIT;
  *message = init_value;
}
size_t protocol__get_successor_list_args__get_packed_size
                     (const Protocol__GetSuccessorListArgs *message)
{
  assert(message->base.descriptor == &protocol__get_successor_list_args__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__get_successor_list_args__pack
                     (const Protocol__GetSuccessorListArgs *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__get_successor_list_args__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__get_successor_list_args__pack_to_buffer
                     (const Protocol__GetSuccessorListArgs *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__get_successor_list_args__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__GetSuccessorListArgs *
       protocol__get_successor_list_args__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__GetSuccessorListArgs *)
     protobuf_c_message_unpack (&protocol__get_successor_list_args__descriptor,
                                allocator, len, data);
}
void   protocol__get_successor_list_args__free_unpacked
                     (Protocol__GetSuccessorListArgs *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__get_successor_list_args__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   protocol__get_successor_list_ret__init
                     (Protocol__GetSuccessorListRet         *message)
{
  static const Protocol__GetSuccessorListRet init_value = PROTOCOL__GET_SUCCESSOR_LIST_RET__INIT;
  *message = init_value;
}
size_t protocol__get_successor_list_ret__get_packed_size
                     (const Protocol__GetSuccessorListRet *message)
{
  assert(message->base.descriptor == &protocol__get_successor_list_ret__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t protocol__get_successor_list_ret__pack
                     (const Protocol__GetSuccessorListRet *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &protocol__get_successor_list_ret__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t protocol__get_successor_list_ret__pack_to_buffer
                     (const Protocol__GetSuccessorListRet *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &protocol__get_successor_list_ret__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Protocol__GetSuccessorListRet *
       protocol__get_successor_list_ret__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Protocol__GetSuccessorListRet *)
     protobuf_c_message_unpack (&protocol__get_successor_list_ret__descriptor,
                                allocator, len, data);
}
void   protocol__get_successor_list_ret__free_unpacked
                     (Protocol__GetSuccessorListRet *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &protocol__get_successor_list_ret__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor protocol__node__field_descriptors[3] =
{
  {
    "id",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(Protocol__Node, id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "address",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Protocol__Node, address),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "port",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(Protocol__Node, port),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned protocol__node__field_indices_by_name[] = {
  1,   /* field[1] = address */
  0,   /* field[0] = id */
  2,   /* field[2] = port */
};
static const ProtobufCIntRange protocol__node__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor protocol__node__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.Node",
  "Node",
  "Protocol__Node",
  "protocol",
  sizeof(Protocol__Node),
  3,
  protocol__node__field_descriptors,
  protocol__node__field_indices_by_name,
  1,  protocol__node__number_ranges,
  (ProtobufCMessageInit) protocol__node__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor protocol__call__field_descriptors[2] =
{
  {
    "name",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Protocol__Call, name),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "args",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(Protocol__Call, args),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned protocol__call__field_indices_by_name[] = {
  1,   /* field[1] = args */
  0,   /* field[0] = name */
};
static const ProtobufCIntRange protocol__call__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor protocol__call__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.Call",
  "Call",
  "Protocol__Call",
  "protocol",
  sizeof(Protocol__Call),
  2,
  protocol__call__field_descriptors,
  protocol__call__field_indices_by_name,
  1,  protocol__call__number_ranges,
  (ProtobufCMessageInit) protocol__call__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor protocol__return__field_descriptors[2] =
{
  {
    "success",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BOOL,
    0,   /* quantifier_offset */
    offsetof(Protocol__Return, success),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "value",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Protocol__Return, has_value),
    offsetof(Protocol__Return, value),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned protocol__return__field_indices_by_name[] = {
  0,   /* field[0] = success */
  1,   /* field[1] = value */
};
static const ProtobufCIntRange protocol__return__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor protocol__return__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.Return",
  "Return",
  "Protocol__Return",
  "protocol",
  sizeof(Protocol__Return),
  2,
  protocol__return__field_descriptors,
  protocol__return__field_indices_by_name,
  1,  protocol__return__number_ranges,
  (ProtobufCMessageInit) protocol__return__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor protocol__find_successor_args__field_descriptors[1] =
{
  {
    "id",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(Protocol__FindSuccessorArgs, id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned protocol__find_successor_args__field_indices_by_name[] = {
  0,   /* field[0] = id */
};
static const ProtobufCIntRange protocol__find_successor_args__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor protocol__find_successor_args__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.FindSuccessorArgs",
  "FindSuccessorArgs",
  "Protocol__FindSuccessorArgs",
  "protocol",
  sizeof(Protocol__FindSuccessorArgs),
  1,
  protocol__find_successor_args__field_descriptors,
  protocol__find_successor_args__field_indices_by_name,
  1,  protocol__find_successor_args__number_ranges,
  (ProtobufCMessageInit) protocol__find_successor_args__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor protocol__find_successor_ret__field_descriptors[1] =
{
  {
    "node",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Protocol__FindSuccessorRet, node),
    &protocol__node__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned protocol__find_successor_ret__field_indices_by_name[] = {
  0,   /* field[0] = node */
};
static const ProtobufCIntRange protocol__find_successor_ret__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor protocol__find_successor_ret__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.FindSuccessorRet",
  "FindSuccessorRet",
  "Protocol__FindSuccessorRet",
  "protocol",
  sizeof(Protocol__FindSuccessorRet),
  1,
  protocol__find_successor_ret__field_descriptors,
  protocol__find_successor_ret__field_indices_by_name,
  1,  protocol__find_successor_ret__number_ranges,
  (ProtobufCMessageInit) protocol__find_successor_ret__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor protocol__notify_args__field_descriptors[1] =
{
  {
    "node",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Protocol__NotifyArgs, node),
    &protocol__node__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned protocol__notify_args__field_indices_by_name[] = {
  0,   /* field[0] = node */
};
static const ProtobufCIntRange protocol__notify_args__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor protocol__notify_args__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.NotifyArgs",
  "NotifyArgs",
  "Protocol__NotifyArgs",
  "protocol",
  sizeof(Protocol__NotifyArgs),
  1,
  protocol__notify_args__field_descriptors,
  protocol__notify_args__field_indices_by_name,
  1,  protocol__notify_args__number_ranges,
  (ProtobufCMessageInit) protocol__notify_args__init,
  NULL,NULL,NULL    /* reserved[123] */
};
#define protocol__notify_ret__field_descriptors NULL
#define protocol__notify_ret__field_indices_by_name NULL
#define protocol__notify_ret__number_ranges NULL
const ProtobufCMessageDescriptor protocol__notify_ret__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.NotifyRet",
  "NotifyRet",
  "Protocol__NotifyRet",
  "protocol",
  sizeof(Protocol__NotifyRet),
  0,
  protocol__notify_ret__field_descriptors,
  protocol__notify_ret__field_indices_by_name,
  0,  protocol__notify_ret__number_ranges,
  (ProtobufCMessageInit) protocol__notify_ret__init,
  NULL,NULL,NULL    /* reserved[123] */
};
#define protocol__check_predecessor_args__field_descriptors NULL
#define protocol__check_predecessor_args__field_indices_by_name NULL
#define protocol__check_predecessor_args__number_ranges NULL
const ProtobufCMessageDescriptor protocol__check_predecessor_args__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.CheckPredecessorArgs",
  "CheckPredecessorArgs",
  "Protocol__CheckPredecessorArgs",
  "protocol",
  sizeof(Protocol__CheckPredecessorArgs),
  0,
  protocol__check_predecessor_args__field_descriptors,
  protocol__check_predecessor_args__field_indices_by_name,
  0,  protocol__check_predecessor_args__number_ranges,
  (ProtobufCMessageInit) protocol__check_predecessor_args__init,
  NULL,NULL,NULL    /* reserved[123] */
};
#define protocol__check_predecessor_ret__field_descriptors NULL
#define protocol__check_predecessor_ret__field_indices_by_name NULL
#define protocol__check_predecessor_ret__number_ranges NULL
const ProtobufCMessageDescriptor protocol__check_predecessor_ret__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.CheckPredecessorRet",
  "CheckPredecessorRet",
  "Protocol__CheckPredecessorRet",
  "protocol",
  sizeof(Protocol__CheckPredecessorRet),
  0,
  protocol__check_predecessor_ret__field_descriptors,
  protocol__check_predecessor_ret__field_indices_by_name,
  0,  protocol__check_predecessor_ret__number_ranges,
  (ProtobufCMessageInit) protocol__check_predecessor_ret__init,
  NULL,NULL,NULL    /* reserved[123] */
};
#define protocol__get_predecessor_args__field_descriptors NULL
#define protocol__get_predecessor_args__field_indices_by_name NULL
#define protocol__get_predecessor_args__number_ranges NULL
const ProtobufCMessageDescriptor protocol__get_predecessor_args__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.GetPredecessorArgs",
  "GetPredecessorArgs",
  "Protocol__GetPredecessorArgs",
  "protocol",
  sizeof(Protocol__GetPredecessorArgs),
  0,
  protocol__get_predecessor_args__field_descriptors,
  protocol__get_predecessor_args__field_indices_by_name,
  0,  protocol__get_predecessor_args__number_ranges,
  (ProtobufCMessageInit) protocol__get_predecessor_args__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor protocol__get_predecessor_ret__field_descriptors[1] =
{
  {
    "node",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Protocol__GetPredecessorRet, node),
    &protocol__node__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned protocol__get_predecessor_ret__field_indices_by_name[] = {
  0,   /* field[0] = node */
};
static const ProtobufCIntRange protocol__get_predecessor_ret__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor protocol__get_predecessor_ret__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.GetPredecessorRet",
  "GetPredecessorRet",
  "Protocol__GetPredecessorRet",
  "protocol",
  sizeof(Protocol__GetPredecessorRet),
  1,
  protocol__get_predecessor_ret__field_descriptors,
  protocol__get_predecessor_ret__field_indices_by_name,
  1,  protocol__get_predecessor_ret__number_ranges,
  (ProtobufCMessageInit) protocol__get_predecessor_ret__init,
  NULL,NULL,NULL    /* reserved[123] */
};
#define protocol__get_successor_list_args__field_descriptors NULL
#define protocol__get_successor_list_args__field_indices_by_name NULL
#define protocol__get_successor_list_args__number_ranges NULL
const ProtobufCMessageDescriptor protocol__get_successor_list_args__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.GetSuccessorListArgs",
  "GetSuccessorListArgs",
  "Protocol__GetSuccessorListArgs",
  "protocol",
  sizeof(Protocol__GetSuccessorListArgs),
  0,
  protocol__get_successor_list_args__field_descriptors,
  protocol__get_successor_list_args__field_indices_by_name,
  0,  protocol__get_successor_list_args__number_ranges,
  (ProtobufCMessageInit) protocol__get_successor_list_args__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor protocol__get_successor_list_ret__field_descriptors[1] =
{
  {
    "successors",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Protocol__GetSuccessorListRet, n_successors),
    offsetof(Protocol__GetSuccessorListRet, successors),
    &protocol__node__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned protocol__get_successor_list_ret__field_indices_by_name[] = {
  0,   /* field[0] = successors */
};
static const ProtobufCIntRange protocol__get_successor_list_ret__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor protocol__get_successor_list_ret__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "protocol.GetSuccessorListRet",
  "GetSuccessorListRet",
  "Protocol__GetSuccessorListRet",
  "protocol",
  sizeof(Protocol__GetSuccessorListRet),
  1,
  protocol__get_successor_list_ret__field_descriptors,
  protocol__get_successor_list_ret__field_indices_by_name,
  1,  protocol__get_successor_list_ret__number_ranges,
  (ProtobufCMessageInit) protocol__get_successor_list_ret__init,
  NULL,NULL,NULL    /* reserved[123] */
};
