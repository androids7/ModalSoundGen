# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: sploosh.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='sploosh.proto',
  package='sploosh',
  serialized_pb=_b('\n\rsploosh.proto\x12\x07sploosh\"4\n\x08Vector3d\x12\x0c\n\x01x\x18\x01 \x01(\x01:\x01\x30\x12\x0c\n\x01y\x18\x02 \x01(\x01:\x01\x30\x12\x0c\n\x01z\x18\x03 \x01(\x01:\x01\x30\",\n\x08\x43omplexd\x12\x0f\n\x04real\x18\x01 \x01(\x01:\x01\x30\x12\x0f\n\x04imag\x18\x02 \x01(\x01:\x01\x30\"^\n\tFMMoments\x12\x0e\n\x06numExp\x18\x01 \x02(\r\x12\x0f\n\x07waveNum\x18\x02 \x02(\x01\x12!\n\x06\x63\x65nter\x18\x03 \x01(\x0b\x32\x11.sploosh.Vector3d\x12\r\n\x05mfile\x18\x04 \x01(\t\"2\n\x0cModalMoments\x12\"\n\x06moment\x18\x01 \x03(\x0b\x32\x12.sploosh.FMMoments')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_VECTOR3D = _descriptor.Descriptor(
  name='Vector3d',
  full_name='sploosh.Vector3d',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='x', full_name='sploosh.Vector3d.x', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='y', full_name='sploosh.Vector3d.y', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='z', full_name='sploosh.Vector3d.z', index=2,
      number=3, type=1, cpp_type=5, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=26,
  serialized_end=78,
)


_COMPLEXD = _descriptor.Descriptor(
  name='Complexd',
  full_name='sploosh.Complexd',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='real', full_name='sploosh.Complexd.real', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='imag', full_name='sploosh.Complexd.imag', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=80,
  serialized_end=124,
)


_FMMOMENTS = _descriptor.Descriptor(
  name='FMMoments',
  full_name='sploosh.FMMoments',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='numExp', full_name='sploosh.FMMoments.numExp', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='waveNum', full_name='sploosh.FMMoments.waveNum', index=1,
      number=2, type=1, cpp_type=5, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='center', full_name='sploosh.FMMoments.center', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='mfile', full_name='sploosh.FMMoments.mfile', index=3,
      number=4, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=126,
  serialized_end=220,
)


_MODALMOMENTS = _descriptor.Descriptor(
  name='ModalMoments',
  full_name='sploosh.ModalMoments',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='moment', full_name='sploosh.ModalMoments.moment', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=222,
  serialized_end=272,
)

_FMMOMENTS.fields_by_name['center'].message_type = _VECTOR3D
_MODALMOMENTS.fields_by_name['moment'].message_type = _FMMOMENTS
DESCRIPTOR.message_types_by_name['Vector3d'] = _VECTOR3D
DESCRIPTOR.message_types_by_name['Complexd'] = _COMPLEXD
DESCRIPTOR.message_types_by_name['FMMoments'] = _FMMOMENTS
DESCRIPTOR.message_types_by_name['ModalMoments'] = _MODALMOMENTS

Vector3d = _reflection.GeneratedProtocolMessageType('Vector3d', (_message.Message,), dict(
  DESCRIPTOR = _VECTOR3D,
  __module__ = 'sploosh_pb2'
  # @@protoc_insertion_point(class_scope:sploosh.Vector3d)
  ))
_sym_db.RegisterMessage(Vector3d)

Complexd = _reflection.GeneratedProtocolMessageType('Complexd', (_message.Message,), dict(
  DESCRIPTOR = _COMPLEXD,
  __module__ = 'sploosh_pb2'
  # @@protoc_insertion_point(class_scope:sploosh.Complexd)
  ))
_sym_db.RegisterMessage(Complexd)

FMMoments = _reflection.GeneratedProtocolMessageType('FMMoments', (_message.Message,), dict(
  DESCRIPTOR = _FMMOMENTS,
  __module__ = 'sploosh_pb2'
  # @@protoc_insertion_point(class_scope:sploosh.FMMoments)
  ))
_sym_db.RegisterMessage(FMMoments)

ModalMoments = _reflection.GeneratedProtocolMessageType('ModalMoments', (_message.Message,), dict(
  DESCRIPTOR = _MODALMOMENTS,
  __module__ = 'sploosh_pb2'
  # @@protoc_insertion_point(class_scope:sploosh.ModalMoments)
  ))
_sym_db.RegisterMessage(ModalMoments)


# @@protoc_insertion_point(module_scope)
