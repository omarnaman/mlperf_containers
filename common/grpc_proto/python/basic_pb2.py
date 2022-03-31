# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: basic.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='basic.proto',
  package='',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x0b\x62\x61sic.proto\"(\n\x0bRequestItem\x12\r\n\x05items\x18\x01 \x01(\x0c\x12\n\n\x02id\x18\x02 \x01(\x04\")\n\nItemResult\x12\x0f\n\x07results\x18\x01 \x01(\x0c\x12\n\n\x02id\x18\x02 \x01(\x04\" \n\rThreadRequest\x12\x0f\n\x07threads\x18\x01 \x01(\x05\"\x19\n\x0bThreadReply\x12\n\n\x02ok\x18\x01 \x01(\x08\x32\x9f\x01\n\x0c\x42\x61sicService\x12*\n\rInferenceItem\x12\x0c.RequestItem\x1a\x0b.ItemResult\x12\x34\n\x13StreamInferenceItem\x12\x0c.RequestItem\x1a\x0b.ItemResult(\x01\x30\x01\x12-\n\rChangeThreads\x12\x0e.ThreadRequest\x1a\x0c.ThreadReplyb\x06proto3'
)




_REQUESTITEM = _descriptor.Descriptor(
  name='RequestItem',
  full_name='RequestItem',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='items', full_name='RequestItem.items', index=0,
      number=1, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='id', full_name='RequestItem.id', index=1,
      number=2, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=15,
  serialized_end=55,
)


_ITEMRESULT = _descriptor.Descriptor(
  name='ItemResult',
  full_name='ItemResult',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='results', full_name='ItemResult.results', index=0,
      number=1, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='id', full_name='ItemResult.id', index=1,
      number=2, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=57,
  serialized_end=98,
)


_THREADREQUEST = _descriptor.Descriptor(
  name='ThreadRequest',
  full_name='ThreadRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='threads', full_name='ThreadRequest.threads', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=100,
  serialized_end=132,
)


_THREADREPLY = _descriptor.Descriptor(
  name='ThreadReply',
  full_name='ThreadReply',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='ok', full_name='ThreadReply.ok', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=134,
  serialized_end=159,
)

DESCRIPTOR.message_types_by_name['RequestItem'] = _REQUESTITEM
DESCRIPTOR.message_types_by_name['ItemResult'] = _ITEMRESULT
DESCRIPTOR.message_types_by_name['ThreadRequest'] = _THREADREQUEST
DESCRIPTOR.message_types_by_name['ThreadReply'] = _THREADREPLY
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

RequestItem = _reflection.GeneratedProtocolMessageType('RequestItem', (_message.Message,), {
  'DESCRIPTOR' : _REQUESTITEM,
  '__module__' : 'basic_pb2'
  # @@protoc_insertion_point(class_scope:RequestItem)
  })
_sym_db.RegisterMessage(RequestItem)

ItemResult = _reflection.GeneratedProtocolMessageType('ItemResult', (_message.Message,), {
  'DESCRIPTOR' : _ITEMRESULT,
  '__module__' : 'basic_pb2'
  # @@protoc_insertion_point(class_scope:ItemResult)
  })
_sym_db.RegisterMessage(ItemResult)

ThreadRequest = _reflection.GeneratedProtocolMessageType('ThreadRequest', (_message.Message,), {
  'DESCRIPTOR' : _THREADREQUEST,
  '__module__' : 'basic_pb2'
  # @@protoc_insertion_point(class_scope:ThreadRequest)
  })
_sym_db.RegisterMessage(ThreadRequest)

ThreadReply = _reflection.GeneratedProtocolMessageType('ThreadReply', (_message.Message,), {
  'DESCRIPTOR' : _THREADREPLY,
  '__module__' : 'basic_pb2'
  # @@protoc_insertion_point(class_scope:ThreadReply)
  })
_sym_db.RegisterMessage(ThreadReply)



_BASICSERVICE = _descriptor.ServiceDescriptor(
  name='BasicService',
  full_name='BasicService',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_start=162,
  serialized_end=321,
  methods=[
  _descriptor.MethodDescriptor(
    name='InferenceItem',
    full_name='BasicService.InferenceItem',
    index=0,
    containing_service=None,
    input_type=_REQUESTITEM,
    output_type=_ITEMRESULT,
    serialized_options=None,
    create_key=_descriptor._internal_create_key,
  ),
  _descriptor.MethodDescriptor(
    name='StreamInferenceItem',
    full_name='BasicService.StreamInferenceItem',
    index=1,
    containing_service=None,
    input_type=_REQUESTITEM,
    output_type=_ITEMRESULT,
    serialized_options=None,
    create_key=_descriptor._internal_create_key,
  ),
  _descriptor.MethodDescriptor(
    name='ChangeThreads',
    full_name='BasicService.ChangeThreads',
    index=2,
    containing_service=None,
    input_type=_THREADREQUEST,
    output_type=_THREADREPLY,
    serialized_options=None,
    create_key=_descriptor._internal_create_key,
  ),
])
_sym_db.RegisterServiceDescriptor(_BASICSERVICE)

DESCRIPTOR.services_by_name['BasicService'] = _BASICSERVICE

# @@protoc_insertion_point(module_scope)
