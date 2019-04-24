// generated by lv2ttl2c from
// http://gareus.org/oss/lv2/meters#bitmeter

extern const LV2_Descriptor* lv2_descriptor(uint32_t index);
extern const LV2UI_Descriptor* lv2ui_bitmeter(uint32_t index);

static const RtkLv2Description _plugin_bitmeter = {
	&lv2_descriptor,
	&lv2ui_bitmeter
	, 31 // uint32_t dsp_descriptor_id
	, 0 // uint32_t gui_descriptor_id
	, "Bit Meter" // const char *plugin_human_id
	, (const struct LV2Port[4])
	{
		{ "control", ATOM_IN, nan, nan, nan, "UI to plugin communication"},
		{ "notify", ATOM_OUT, nan, nan, nan, "plugin to UI communication"},
		{ "in", AUDIO_IN, nan, nan, nan, "In"},
		{ "out", AUDIO_OUT, nan, nan, nan, "Out"},
	}
	, 4 // uint32_t nports_total
	, 1 // uint32_t nports_audio_in
	, 1 // uint32_t nports_audio_out
	, 0 // uint32_t nports_midi_in
	, 0 // uint32_t nports_midi_out
	, 1 // uint32_t nports_atom_in
	, 1 // uint32_t nports_atom_out
	, 0 // uint32_t nports_ctrl
	, 0 // uint32_t nports_ctrl_in
	, 0 // uint32_t nports_ctrl_out
	, 8192 // uint32_t min_atom_bufsiz
	, false // bool send_time_info
	, UINT32_MAX // uint32_t latency_ctrl_port
};


#ifdef X42_PLUGIN_STRUCT
#undef X42_PLUGIN_STRUCT
#endif
#define X42_PLUGIN_STRUCT _plugin_bitmeter