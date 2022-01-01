// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: basic.proto

#include "basic.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr RequestItem::RequestItem(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : items_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , id_(0){}
struct RequestItemDefaultTypeInternal {
  constexpr RequestItemDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RequestItemDefaultTypeInternal() {}
  union {
    RequestItem _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RequestItemDefaultTypeInternal _RequestItem_default_instance_;
constexpr ItemResult::ItemResult(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : results_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , id_(0){}
struct ItemResultDefaultTypeInternal {
  constexpr ItemResultDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ItemResultDefaultTypeInternal() {}
  union {
    ItemResult _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ItemResultDefaultTypeInternal _ItemResult_default_instance_;
constexpr ThreadRequest::ThreadRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : threads_(0){}
struct ThreadRequestDefaultTypeInternal {
  constexpr ThreadRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ThreadRequestDefaultTypeInternal() {}
  union {
    ThreadRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ThreadRequestDefaultTypeInternal _ThreadRequest_default_instance_;
constexpr ThreadReply::ThreadReply(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : ok_(false){}
struct ThreadReplyDefaultTypeInternal {
  constexpr ThreadReplyDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ThreadReplyDefaultTypeInternal() {}
  union {
    ThreadReply _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ThreadReplyDefaultTypeInternal _ThreadReply_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_basic_2eproto[4];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_basic_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_basic_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_basic_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::RequestItem, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::RequestItem, items_),
  PROTOBUF_FIELD_OFFSET(::RequestItem, id_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ItemResult, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ItemResult, results_),
  PROTOBUF_FIELD_OFFSET(::ItemResult, id_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ThreadRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ThreadRequest, threads_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ThreadReply, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ThreadReply, ok_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::RequestItem)},
  { 8, -1, -1, sizeof(::ItemResult)},
  { 16, -1, -1, sizeof(::ThreadRequest)},
  { 23, -1, -1, sizeof(::ThreadReply)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_RequestItem_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ItemResult_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ThreadRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ThreadReply_default_instance_),
};

const char descriptor_table_protodef_basic_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013basic.proto\"(\n\013RequestItem\022\r\n\005items\030\001 "
  "\001(\014\022\n\n\002id\030\002 \001(\005\")\n\nItemResult\022\017\n\007results"
  "\030\001 \001(\014\022\n\n\002id\030\002 \001(\005\" \n\rThreadRequest\022\017\n\007t"
  "hreads\030\001 \001(\005\"\031\n\013ThreadReply\022\n\n\002ok\030\001 \001(\0102"
  "\237\001\n\014BasicService\022*\n\rInferenceItem\022\014.Requ"
  "estItem\032\013.ItemResult\0224\n\023StreamInferenceI"
  "tem\022\014.RequestItem\032\013.ItemResult(\0010\001\022-\n\rCh"
  "angeThreads\022\016.ThreadRequest\032\014.ThreadRepl"
  "yb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_basic_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_basic_2eproto = {
  false, false, 329, descriptor_table_protodef_basic_2eproto, "basic.proto", 
  &descriptor_table_basic_2eproto_once, nullptr, 0, 4,
  schemas, file_default_instances, TableStruct_basic_2eproto::offsets,
  file_level_metadata_basic_2eproto, file_level_enum_descriptors_basic_2eproto, file_level_service_descriptors_basic_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_basic_2eproto_getter() {
  return &descriptor_table_basic_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_basic_2eproto(&descriptor_table_basic_2eproto);

// ===================================================================

class RequestItem::_Internal {
 public:
};

RequestItem::RequestItem(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:RequestItem)
}
RequestItem::RequestItem(const RequestItem& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  items_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_items().empty()) {
    items_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_items(), 
      GetArenaForAllocation());
  }
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:RequestItem)
}

void RequestItem::SharedCtor() {
items_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
id_ = 0;
}

RequestItem::~RequestItem() {
  // @@protoc_insertion_point(destructor:RequestItem)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void RequestItem::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  items_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RequestItem::ArenaDtor(void* object) {
  RequestItem* _this = reinterpret_cast< RequestItem* >(object);
  (void)_this;
}
void RequestItem::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RequestItem::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void RequestItem::Clear() {
// @@protoc_insertion_point(message_clear_start:RequestItem)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  items_.ClearToEmpty();
  id_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RequestItem::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bytes items = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_items();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RequestItem::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:RequestItem)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes items = 1;
  if (!this->_internal_items().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_items(), target);
  }

  // int32 id = 2;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:RequestItem)
  return target;
}

size_t RequestItem::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:RequestItem)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes items = 1;
  if (!this->_internal_items().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_items());
  }

  // int32 id = 2;
  if (this->_internal_id() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData RequestItem::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    RequestItem::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*RequestItem::GetClassData() const { return &_class_data_; }

void RequestItem::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<RequestItem *>(to)->MergeFrom(
      static_cast<const RequestItem &>(from));
}


void RequestItem::MergeFrom(const RequestItem& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:RequestItem)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_items().empty()) {
    _internal_set_items(from._internal_items());
  }
  if (from._internal_id() != 0) {
    _internal_set_id(from._internal_id());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void RequestItem::CopyFrom(const RequestItem& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:RequestItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RequestItem::IsInitialized() const {
  return true;
}

void RequestItem::InternalSwap(RequestItem* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &items_, lhs_arena,
      &other->items_, rhs_arena
  );
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata RequestItem::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_basic_2eproto_getter, &descriptor_table_basic_2eproto_once,
      file_level_metadata_basic_2eproto[0]);
}

// ===================================================================

class ItemResult::_Internal {
 public:
};

ItemResult::ItemResult(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:ItemResult)
}
ItemResult::ItemResult(const ItemResult& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  results_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_results().empty()) {
    results_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_results(), 
      GetArenaForAllocation());
  }
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:ItemResult)
}

void ItemResult::SharedCtor() {
results_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
id_ = 0;
}

ItemResult::~ItemResult() {
  // @@protoc_insertion_point(destructor:ItemResult)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void ItemResult::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  results_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ItemResult::ArenaDtor(void* object) {
  ItemResult* _this = reinterpret_cast< ItemResult* >(object);
  (void)_this;
}
void ItemResult::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ItemResult::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ItemResult::Clear() {
// @@protoc_insertion_point(message_clear_start:ItemResult)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  results_.ClearToEmpty();
  id_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ItemResult::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bytes results = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_results();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ItemResult::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ItemResult)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes results = 1;
  if (!this->_internal_results().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_results(), target);
  }

  // int32 id = 2;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ItemResult)
  return target;
}

size_t ItemResult::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ItemResult)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes results = 1;
  if (!this->_internal_results().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_results());
  }

  // int32 id = 2;
  if (this->_internal_id() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ItemResult::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ItemResult::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ItemResult::GetClassData() const { return &_class_data_; }

void ItemResult::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ItemResult *>(to)->MergeFrom(
      static_cast<const ItemResult &>(from));
}


void ItemResult::MergeFrom(const ItemResult& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ItemResult)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_results().empty()) {
    _internal_set_results(from._internal_results());
  }
  if (from._internal_id() != 0) {
    _internal_set_id(from._internal_id());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ItemResult::CopyFrom(const ItemResult& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ItemResult)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ItemResult::IsInitialized() const {
  return true;
}

void ItemResult::InternalSwap(ItemResult* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &results_, lhs_arena,
      &other->results_, rhs_arena
  );
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ItemResult::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_basic_2eproto_getter, &descriptor_table_basic_2eproto_once,
      file_level_metadata_basic_2eproto[1]);
}

// ===================================================================

class ThreadRequest::_Internal {
 public:
};

ThreadRequest::ThreadRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:ThreadRequest)
}
ThreadRequest::ThreadRequest(const ThreadRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  threads_ = from.threads_;
  // @@protoc_insertion_point(copy_constructor:ThreadRequest)
}

void ThreadRequest::SharedCtor() {
threads_ = 0;
}

ThreadRequest::~ThreadRequest() {
  // @@protoc_insertion_point(destructor:ThreadRequest)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void ThreadRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void ThreadRequest::ArenaDtor(void* object) {
  ThreadRequest* _this = reinterpret_cast< ThreadRequest* >(object);
  (void)_this;
}
void ThreadRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ThreadRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ThreadRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:ThreadRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  threads_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ThreadRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 threads = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          threads_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ThreadRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ThreadRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 threads = 1;
  if (this->_internal_threads() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_threads(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ThreadRequest)
  return target;
}

size_t ThreadRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ThreadRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 threads = 1;
  if (this->_internal_threads() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_threads());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ThreadRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ThreadRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ThreadRequest::GetClassData() const { return &_class_data_; }

void ThreadRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ThreadRequest *>(to)->MergeFrom(
      static_cast<const ThreadRequest &>(from));
}


void ThreadRequest::MergeFrom(const ThreadRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ThreadRequest)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_threads() != 0) {
    _internal_set_threads(from._internal_threads());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ThreadRequest::CopyFrom(const ThreadRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ThreadRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ThreadRequest::IsInitialized() const {
  return true;
}

void ThreadRequest::InternalSwap(ThreadRequest* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(threads_, other->threads_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ThreadRequest::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_basic_2eproto_getter, &descriptor_table_basic_2eproto_once,
      file_level_metadata_basic_2eproto[2]);
}

// ===================================================================

class ThreadReply::_Internal {
 public:
};

ThreadReply::ThreadReply(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:ThreadReply)
}
ThreadReply::ThreadReply(const ThreadReply& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ok_ = from.ok_;
  // @@protoc_insertion_point(copy_constructor:ThreadReply)
}

void ThreadReply::SharedCtor() {
ok_ = false;
}

ThreadReply::~ThreadReply() {
  // @@protoc_insertion_point(destructor:ThreadReply)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void ThreadReply::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void ThreadReply::ArenaDtor(void* object) {
  ThreadReply* _this = reinterpret_cast< ThreadReply* >(object);
  (void)_this;
}
void ThreadReply::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ThreadReply::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ThreadReply::Clear() {
// @@protoc_insertion_point(message_clear_start:ThreadReply)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ok_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ThreadReply::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool ok = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ok_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ThreadReply::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ThreadReply)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool ok = 1;
  if (this->_internal_ok() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_ok(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ThreadReply)
  return target;
}

size_t ThreadReply::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ThreadReply)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bool ok = 1;
  if (this->_internal_ok() != 0) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ThreadReply::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ThreadReply::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ThreadReply::GetClassData() const { return &_class_data_; }

void ThreadReply::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ThreadReply *>(to)->MergeFrom(
      static_cast<const ThreadReply &>(from));
}


void ThreadReply::MergeFrom(const ThreadReply& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ThreadReply)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_ok() != 0) {
    _internal_set_ok(from._internal_ok());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ThreadReply::CopyFrom(const ThreadReply& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ThreadReply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ThreadReply::IsInitialized() const {
  return true;
}

void ThreadReply::InternalSwap(ThreadReply* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(ok_, other->ok_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ThreadReply::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_basic_2eproto_getter, &descriptor_table_basic_2eproto_once,
      file_level_metadata_basic_2eproto[3]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::RequestItem* Arena::CreateMaybeMessage< ::RequestItem >(Arena* arena) {
  return Arena::CreateMessageInternal< ::RequestItem >(arena);
}
template<> PROTOBUF_NOINLINE ::ItemResult* Arena::CreateMaybeMessage< ::ItemResult >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ItemResult >(arena);
}
template<> PROTOBUF_NOINLINE ::ThreadRequest* Arena::CreateMaybeMessage< ::ThreadRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ThreadRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::ThreadReply* Arena::CreateMaybeMessage< ::ThreadReply >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ThreadReply >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>