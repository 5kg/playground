#pragma once

/*
 * A tiny library of C macro metaprogramming like Boost.Preprocessor.
 *
 * Some techniques used here are very similar to C++ template meta-programming,
 * say std::enable_if.
 *
 * References:
 *   - http://stackoverflow.com/a/12540675/385436
 *   - https://github.com/pfultz2/Cloak/wiki/Is-the-C-preprocessor-Turing-complete%3F
 *   - https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms
 */

/* Utilities */
#define CAT(a, ...) a ## __VA_ARGS__

#define NOT(x) CAT(NOT_, x)
#define NOT_0 1
#define NOT_1 0

/* Equality predictor with arguments pattern matching */
#define MATCH(_, val, ...) val

#define EQ(a, b) EQ_IMPL(EQ_ ## a ## _ ## b)
#define EQ_IMPL(...) MATCH(__VA_ARGS__, 0)

#define TRUE _, 1
#define EQ_0_0 TRUE
#define EQ_1_1 TRUE
#define EQ_2_2 TRUE
#define EQ_3_3 TRUE
#define EQ_4_4 TRUE
#define EQ_5_5 TRUE
#define EQ_6_6 TRUE
#define EQ_7_7 TRUE
#define EQ_8_8 TRUE
#define EQ_9_9 TRUE
#define EQ_10_10 TRUE
#define EQ_11_11 TRUE
#define EQ_12_12 TRUE
#define EQ_13_13 TRUE
#define EQ_14_14 TRUE
#define EQ_15_15 TRUE
#define EQ_16_16 TRUE
#define EQ_17_17 TRUE
#define EQ_18_18 TRUE
#define EQ_19_19 TRUE
#define EQ_20_20 TRUE
#define EQ_21_21 TRUE
#define EQ_22_22 TRUE
#define EQ_23_23 TRUE
#define EQ_24_24 TRUE
#define EQ_25_25 TRUE
#define EQ_26_26 TRUE
#define EQ_27_27 TRUE
#define EQ_28_28 TRUE
#define EQ_29_29 TRUE
#define EQ_30_30 TRUE
#define EQ_31_31 TRUE
#define EQ_32_32 TRUE
#define EQ_33_33 TRUE
#define EQ_34_34 TRUE
#define EQ_35_35 TRUE
#define EQ_36_36 TRUE
#define EQ_37_37 TRUE
#define EQ_38_38 TRUE
#define EQ_39_39 TRUE
#define EQ_40_40 TRUE
#define EQ_41_41 TRUE
#define EQ_42_42 TRUE
#define EQ_43_43 TRUE
#define EQ_44_44 TRUE
#define EQ_45_45 TRUE
#define EQ_46_46 TRUE
#define EQ_47_47 TRUE
#define EQ_48_48 TRUE
#define EQ_49_49 TRUE
#define EQ_50_50 TRUE
#define EQ_51_51 TRUE
#define EQ_52_52 TRUE
#define EQ_53_53 TRUE
#define EQ_54_54 TRUE
#define EQ_55_55 TRUE
#define EQ_56_56 TRUE
#define EQ_57_57 TRUE
#define EQ_58_58 TRUE
#define EQ_59_59 TRUE
#define EQ_60_60 TRUE
#define EQ_61_61 TRUE
#define EQ_62_62 TRUE
#define EQ_63_63 TRUE
#define EQ_64_64 TRUE
#define EQ_65_65 TRUE
#define EQ_66_66 TRUE
#define EQ_67_67 TRUE
#define EQ_68_68 TRUE
#define EQ_69_69 TRUE
#define EQ_70_70 TRUE
#define EQ_71_71 TRUE
#define EQ_72_72 TRUE
#define EQ_73_73 TRUE
#define EQ_74_74 TRUE
#define EQ_75_75 TRUE
#define EQ_76_76 TRUE
#define EQ_77_77 TRUE
#define EQ_78_78 TRUE
#define EQ_79_79 TRUE
#define EQ_80_80 TRUE
#define EQ_81_81 TRUE
#define EQ_82_82 TRUE
#define EQ_83_83 TRUE
#define EQ_84_84 TRUE
#define EQ_85_85 TRUE
#define EQ_86_86 TRUE
#define EQ_87_87 TRUE
#define EQ_88_88 TRUE
#define EQ_89_89 TRUE
#define EQ_90_90 TRUE
#define EQ_91_91 TRUE
#define EQ_92_92 TRUE
#define EQ_93_93 TRUE
#define EQ_94_94 TRUE
#define EQ_95_95 TRUE
#define EQ_96_96 TRUE
#define EQ_97_97 TRUE
#define EQ_98_98 TRUE
#define EQ_99_99 TRUE
#define EQ_100_100 TRUE
#define EQ_101_101 TRUE
#define EQ_102_102 TRUE
#define EQ_103_103 TRUE
#define EQ_104_104 TRUE
#define EQ_105_105 TRUE
#define EQ_106_106 TRUE
#define EQ_107_107 TRUE
#define EQ_108_108 TRUE
#define EQ_109_109 TRUE
#define EQ_110_110 TRUE
#define EQ_111_111 TRUE
#define EQ_112_112 TRUE
#define EQ_113_113 TRUE
#define EQ_114_114 TRUE
#define EQ_115_115 TRUE
#define EQ_116_116 TRUE
#define EQ_117_117 TRUE
#define EQ_118_118 TRUE
#define EQ_119_119 TRUE
#define EQ_120_120 TRUE
#define EQ_121_121 TRUE
#define EQ_122_122 TRUE
#define EQ_123_123 TRUE
#define EQ_124_124 TRUE
#define EQ_125_125 TRUE
#define EQ_126_126 TRUE
#define EQ_127_127 TRUE
#define EQ_128_128 TRUE
#define EQ_129_129 TRUE
#define EQ_130_130 TRUE
#define EQ_131_131 TRUE
#define EQ_132_132 TRUE
#define EQ_133_133 TRUE
#define EQ_134_134 TRUE
#define EQ_135_135 TRUE
#define EQ_136_136 TRUE
#define EQ_137_137 TRUE
#define EQ_138_138 TRUE
#define EQ_139_139 TRUE
#define EQ_140_140 TRUE
#define EQ_141_141 TRUE
#define EQ_142_142 TRUE
#define EQ_143_143 TRUE
#define EQ_144_144 TRUE
#define EQ_145_145 TRUE
#define EQ_146_146 TRUE
#define EQ_147_147 TRUE
#define EQ_148_148 TRUE
#define EQ_149_149 TRUE
#define EQ_150_150 TRUE
#define EQ_151_151 TRUE
#define EQ_152_152 TRUE
#define EQ_153_153 TRUE
#define EQ_154_154 TRUE
#define EQ_155_155 TRUE
#define EQ_156_156 TRUE
#define EQ_157_157 TRUE
#define EQ_158_158 TRUE
#define EQ_159_159 TRUE
#define EQ_160_160 TRUE
#define EQ_161_161 TRUE
#define EQ_162_162 TRUE
#define EQ_163_163 TRUE
#define EQ_164_164 TRUE
#define EQ_165_165 TRUE
#define EQ_166_166 TRUE
#define EQ_167_167 TRUE
#define EQ_168_168 TRUE
#define EQ_169_169 TRUE
#define EQ_170_170 TRUE
#define EQ_171_171 TRUE
#define EQ_172_172 TRUE
#define EQ_173_173 TRUE
#define EQ_174_174 TRUE
#define EQ_175_175 TRUE
#define EQ_176_176 TRUE
#define EQ_177_177 TRUE
#define EQ_178_178 TRUE
#define EQ_179_179 TRUE
#define EQ_180_180 TRUE
#define EQ_181_181 TRUE
#define EQ_182_182 TRUE
#define EQ_183_183 TRUE
#define EQ_184_184 TRUE
#define EQ_185_185 TRUE
#define EQ_186_186 TRUE
#define EQ_187_187 TRUE
#define EQ_188_188 TRUE
#define EQ_189_189 TRUE
#define EQ_190_190 TRUE
#define EQ_191_191 TRUE
#define EQ_192_192 TRUE
#define EQ_193_193 TRUE
#define EQ_194_194 TRUE
#define EQ_195_195 TRUE
#define EQ_196_196 TRUE
#define EQ_197_197 TRUE
#define EQ_198_198 TRUE
#define EQ_199_199 TRUE
#define EQ_200_200 TRUE
#define EQ_201_201 TRUE
#define EQ_202_202 TRUE
#define EQ_203_203 TRUE
#define EQ_204_204 TRUE
#define EQ_205_205 TRUE
#define EQ_206_206 TRUE
#define EQ_207_207 TRUE
#define EQ_208_208 TRUE
#define EQ_209_209 TRUE
#define EQ_210_210 TRUE
#define EQ_211_211 TRUE
#define EQ_212_212 TRUE
#define EQ_213_213 TRUE
#define EQ_214_214 TRUE
#define EQ_215_215 TRUE
#define EQ_216_216 TRUE
#define EQ_217_217 TRUE
#define EQ_218_218 TRUE
#define EQ_219_219 TRUE
#define EQ_220_220 TRUE
#define EQ_221_221 TRUE
#define EQ_222_222 TRUE
#define EQ_223_223 TRUE
#define EQ_224_224 TRUE
#define EQ_225_225 TRUE
#define EQ_226_226 TRUE
#define EQ_227_227 TRUE
#define EQ_228_228 TRUE
#define EQ_229_229 TRUE
#define EQ_230_230 TRUE
#define EQ_231_231 TRUE
#define EQ_232_232 TRUE
#define EQ_233_233 TRUE
#define EQ_234_234 TRUE
#define EQ_235_235 TRUE
#define EQ_236_236 TRUE
#define EQ_237_237 TRUE
#define EQ_238_238 TRUE
#define EQ_239_239 TRUE
#define EQ_240_240 TRUE
#define EQ_241_241 TRUE
#define EQ_242_242 TRUE
#define EQ_243_243 TRUE
#define EQ_244_244 TRUE
#define EQ_245_245 TRUE
#define EQ_246_246 TRUE
#define EQ_247_247 TRUE
#define EQ_248_248 TRUE
#define EQ_249_249 TRUE
#define EQ_250_250 TRUE
#define EQ_251_251 TRUE
#define EQ_252_252 TRUE
#define EQ_253_253 TRUE
#define EQ_254_254 TRUE
#define EQ_255_255 TRUE

/* Increment and decrement */
#define INC(x) CAT(INC_, x)
#define INC_0 1
#define INC_1 2
#define INC_2 3
#define INC_3 4
#define INC_4 5
#define INC_5 6
#define INC_6 7
#define INC_7 8
#define INC_8 9
#define INC_9 10
#define INC_10 11
#define INC_11 12
#define INC_12 13
#define INC_13 14
#define INC_14 15
#define INC_15 16
#define INC_16 17
#define INC_17 18
#define INC_18 19
#define INC_19 20
#define INC_20 21
#define INC_21 22
#define INC_22 23
#define INC_23 24
#define INC_24 25
#define INC_25 26
#define INC_26 27
#define INC_27 28
#define INC_28 29
#define INC_29 30
#define INC_30 31
#define INC_31 32
#define INC_32 33
#define INC_33 34
#define INC_34 35
#define INC_35 36
#define INC_36 37
#define INC_37 38
#define INC_38 39
#define INC_39 40
#define INC_40 41
#define INC_41 42
#define INC_42 43
#define INC_43 44
#define INC_44 45
#define INC_45 46
#define INC_46 47
#define INC_47 48
#define INC_48 49
#define INC_49 50
#define INC_50 51
#define INC_51 52
#define INC_52 53
#define INC_53 54
#define INC_54 55
#define INC_55 56
#define INC_56 57
#define INC_57 58
#define INC_58 59
#define INC_59 60
#define INC_60 61
#define INC_61 62
#define INC_62 63
#define INC_63 64
#define INC_64 65
#define INC_65 66
#define INC_66 67
#define INC_67 68
#define INC_68 69
#define INC_69 70
#define INC_70 71
#define INC_71 72
#define INC_72 73
#define INC_73 74
#define INC_74 75
#define INC_75 76
#define INC_76 77
#define INC_77 78
#define INC_78 79
#define INC_79 80
#define INC_80 81
#define INC_81 82
#define INC_82 83
#define INC_83 84
#define INC_84 85
#define INC_85 86
#define INC_86 87
#define INC_87 88
#define INC_88 89
#define INC_89 90
#define INC_90 91
#define INC_91 92
#define INC_92 93
#define INC_93 94
#define INC_94 95
#define INC_95 96
#define INC_96 97
#define INC_97 98
#define INC_98 99
#define INC_99 100
#define INC_100 101
#define INC_101 102
#define INC_102 103
#define INC_103 104
#define INC_104 105
#define INC_105 106
#define INC_106 107
#define INC_107 108
#define INC_108 109
#define INC_109 110
#define INC_110 111
#define INC_111 112
#define INC_112 113
#define INC_113 114
#define INC_114 115
#define INC_115 116
#define INC_116 117
#define INC_117 118
#define INC_118 119
#define INC_119 120
#define INC_120 121
#define INC_121 122
#define INC_122 123
#define INC_123 124
#define INC_124 125
#define INC_125 126
#define INC_126 127
#define INC_127 128
#define INC_128 129
#define INC_129 130
#define INC_130 131
#define INC_131 132
#define INC_132 133
#define INC_133 134
#define INC_134 135
#define INC_135 136
#define INC_136 137
#define INC_137 138
#define INC_138 139
#define INC_139 140
#define INC_140 141
#define INC_141 142
#define INC_142 143
#define INC_143 144
#define INC_144 145
#define INC_145 146
#define INC_146 147
#define INC_147 148
#define INC_148 149
#define INC_149 150
#define INC_150 151
#define INC_151 152
#define INC_152 153
#define INC_153 154
#define INC_154 155
#define INC_155 156
#define INC_156 157
#define INC_157 158
#define INC_158 159
#define INC_159 160
#define INC_160 161
#define INC_161 162
#define INC_162 163
#define INC_163 164
#define INC_164 165
#define INC_165 166
#define INC_166 167
#define INC_167 168
#define INC_168 169
#define INC_169 170
#define INC_170 171
#define INC_171 172
#define INC_172 173
#define INC_173 174
#define INC_174 175
#define INC_175 176
#define INC_176 177
#define INC_177 178
#define INC_178 179
#define INC_179 180
#define INC_180 181
#define INC_181 182
#define INC_182 183
#define INC_183 184
#define INC_184 185
#define INC_185 186
#define INC_186 187
#define INC_187 188
#define INC_188 189
#define INC_189 190
#define INC_190 191
#define INC_191 192
#define INC_192 193
#define INC_193 194
#define INC_194 195
#define INC_195 196
#define INC_196 197
#define INC_197 198
#define INC_198 199
#define INC_199 200
#define INC_200 201
#define INC_201 202
#define INC_202 203
#define INC_203 204
#define INC_204 205
#define INC_205 206
#define INC_206 207
#define INC_207 208
#define INC_208 209
#define INC_209 210
#define INC_210 211
#define INC_211 212
#define INC_212 213
#define INC_213 214
#define INC_214 215
#define INC_215 216
#define INC_216 217
#define INC_217 218
#define INC_218 219
#define INC_219 220
#define INC_220 221
#define INC_221 222
#define INC_222 223
#define INC_223 224
#define INC_224 225
#define INC_225 226
#define INC_226 227
#define INC_227 228
#define INC_228 229
#define INC_229 230
#define INC_230 231
#define INC_231 232
#define INC_232 233
#define INC_233 234
#define INC_234 235
#define INC_235 236
#define INC_236 237
#define INC_237 238
#define INC_238 239
#define INC_239 240
#define INC_240 241
#define INC_241 242
#define INC_242 243
#define INC_243 244
#define INC_244 245
#define INC_245 246
#define INC_246 247
#define INC_247 248
#define INC_248 249
#define INC_249 250
#define INC_250 251
#define INC_251 252
#define INC_252 253
#define INC_253 254
#define INC_254 255

#define DEC(x) CAT(DEC_, x)
#define DEC_1 0
#define DEC_2 1
#define DEC_3 2
#define DEC_4 3
#define DEC_5 4
#define DEC_6 5
#define DEC_7 6
#define DEC_8 7
#define DEC_9 8
#define DEC_10 9
#define DEC_11 10
#define DEC_12 11
#define DEC_13 12
#define DEC_14 13
#define DEC_15 14
#define DEC_16 15
#define DEC_17 16
#define DEC_18 17
#define DEC_19 18
#define DEC_20 19
#define DEC_21 20
#define DEC_22 21
#define DEC_23 22
#define DEC_24 23
#define DEC_25 24
#define DEC_26 25
#define DEC_27 26
#define DEC_28 27
#define DEC_29 28
#define DEC_30 29
#define DEC_31 30
#define DEC_32 31
#define DEC_33 32
#define DEC_34 33
#define DEC_35 34
#define DEC_36 35
#define DEC_37 36
#define DEC_38 37
#define DEC_39 38
#define DEC_40 39
#define DEC_41 40
#define DEC_42 41
#define DEC_43 42
#define DEC_44 43
#define DEC_45 44
#define DEC_46 45
#define DEC_47 46
#define DEC_48 47
#define DEC_49 48
#define DEC_50 49
#define DEC_51 50
#define DEC_52 51
#define DEC_53 52
#define DEC_54 53
#define DEC_55 54
#define DEC_56 55
#define DEC_57 56
#define DEC_58 57
#define DEC_59 58
#define DEC_60 59
#define DEC_61 60
#define DEC_62 61
#define DEC_63 62
#define DEC_64 63
#define DEC_65 64
#define DEC_66 65
#define DEC_67 66
#define DEC_68 67
#define DEC_69 68
#define DEC_70 69
#define DEC_71 70
#define DEC_72 71
#define DEC_73 72
#define DEC_74 73
#define DEC_75 74
#define DEC_76 75
#define DEC_77 76
#define DEC_78 77
#define DEC_79 78
#define DEC_80 79
#define DEC_81 80
#define DEC_82 81
#define DEC_83 82
#define DEC_84 83
#define DEC_85 84
#define DEC_86 85
#define DEC_87 86
#define DEC_88 87
#define DEC_89 88
#define DEC_90 89
#define DEC_91 90
#define DEC_92 91
#define DEC_93 92
#define DEC_94 93
#define DEC_95 94
#define DEC_96 95
#define DEC_97 96
#define DEC_98 97
#define DEC_99 98
#define DEC_100 99
#define DEC_101 100
#define DEC_102 101
#define DEC_103 102
#define DEC_104 103
#define DEC_105 104
#define DEC_106 105
#define DEC_107 106
#define DEC_108 107
#define DEC_109 108
#define DEC_110 109
#define DEC_111 110
#define DEC_112 111
#define DEC_113 112
#define DEC_114 113
#define DEC_115 114
#define DEC_116 115
#define DEC_117 116
#define DEC_118 117
#define DEC_119 118
#define DEC_120 119
#define DEC_121 120
#define DEC_122 121
#define DEC_123 122
#define DEC_124 123
#define DEC_125 124
#define DEC_126 125
#define DEC_127 126
#define DEC_128 127
#define DEC_129 128
#define DEC_130 129
#define DEC_131 130
#define DEC_132 131
#define DEC_133 132
#define DEC_134 133
#define DEC_135 134
#define DEC_136 135
#define DEC_137 136
#define DEC_138 137
#define DEC_139 138
#define DEC_140 139
#define DEC_141 140
#define DEC_142 141
#define DEC_143 142
#define DEC_144 143
#define DEC_145 144
#define DEC_146 145
#define DEC_147 146
#define DEC_148 147
#define DEC_149 148
#define DEC_150 149
#define DEC_151 150
#define DEC_152 151
#define DEC_153 152
#define DEC_154 153
#define DEC_155 154
#define DEC_156 155
#define DEC_157 156
#define DEC_158 157
#define DEC_159 158
#define DEC_160 159
#define DEC_161 160
#define DEC_162 161
#define DEC_163 162
#define DEC_164 163
#define DEC_165 164
#define DEC_166 165
#define DEC_167 166
#define DEC_168 167
#define DEC_169 168
#define DEC_170 169
#define DEC_171 170
#define DEC_172 171
#define DEC_173 172
#define DEC_174 173
#define DEC_175 174
#define DEC_176 175
#define DEC_177 176
#define DEC_178 177
#define DEC_179 178
#define DEC_180 179
#define DEC_181 180
#define DEC_182 181
#define DEC_183 182
#define DEC_184 183
#define DEC_185 184
#define DEC_186 185
#define DEC_187 186
#define DEC_188 187
#define DEC_189 188
#define DEC_190 189
#define DEC_191 190
#define DEC_192 191
#define DEC_193 192
#define DEC_194 193
#define DEC_195 194
#define DEC_196 195
#define DEC_197 196
#define DEC_198 197
#define DEC_199 198
#define DEC_200 199
#define DEC_201 200
#define DEC_202 201
#define DEC_203 202
#define DEC_204 203
#define DEC_205 204
#define DEC_206 205
#define DEC_207 206
#define DEC_208 207
#define DEC_209 208
#define DEC_210 209
#define DEC_211 210
#define DEC_212 211
#define DEC_213 212
#define DEC_214 213
#define DEC_215 214
#define DEC_216 215
#define DEC_217 216
#define DEC_218 217
#define DEC_219 218
#define DEC_220 219
#define DEC_221 220
#define DEC_222 221
#define DEC_223 222
#define DEC_224 223
#define DEC_225 224
#define DEC_226 225
#define DEC_227 226
#define DEC_228 227
#define DEC_229 228
#define DEC_230 229
#define DEC_231 230
#define DEC_232 231
#define DEC_233 232
#define DEC_234 233
#define DEC_235 234
#define DEC_236 235
#define DEC_237 236
#define DEC_238 237
#define DEC_239 238
#define DEC_240 239
#define DEC_241 240
#define DEC_242 241
#define DEC_243 242
#define DEC_244 243
#define DEC_245 244
#define DEC_246 245
#define DEC_247 246
#define DEC_248 247
#define DEC_249 248
#define DEC_250 249
#define DEC_251 250
#define DEC_252 251
#define DEC_253 252
#define DEC_254 253
#define DEC_255 254

/* Control flow */
#define IF(cond) CAT(IF_, cond)
#define IF_0(...)
#define IF_1(...) __VA_ARGS__

/* Recursive expansion: maximum recursion depth is 2^9 = 512 */
#define EXPAND(...)  EXPAND1(EXPAND1(__VA_ARGS__))
#define EXPAND1(...) EXPAND2(EXPAND2(__VA_ARGS__))
#define EXPAND2(...) EXPAND3(EXPAND3(__VA_ARGS__))
#define EXPAND3(...) EXPAND4(EXPAND4(__VA_ARGS__))
#define EXPAND4(...) EXPAND5(EXPAND5(__VA_ARGS__))
#define EXPAND5(...) EXPAND6(EXPAND6(__VA_ARGS__))
#define EXPAND6(...) EXPAND7(EXPAND7(__VA_ARGS__))
#define EXPAND7(...) EXPAND8(EXPAND8(__VA_ARGS__))
#define EXPAND8(...) __VA_ARGS__

/* Deferred expression:
 * The C preprocessor will not recursively expand a same macro in a single scan,
 * thus we will have to defer certain macro expansion in future scan steps.
 */
#define EMPTY(...)
#define DEFER(...) __VA_ARGS__ EMPTY()
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()

/*
 * REPEAT_FROM_TO(start, end, M, ...):
 * Repeatedly expand macro M from start to end. The first argument passed
 * to M will be the index. Possible variadic arguments will also be passed to M.
 *
 * Example:
 *     #define M(id, str) printf(str, id);
 *     REPEAT_FROM_TO(1, 3, M, "id = %d\n")
 * will generate:
 *     printf("id = %d\n", 1); printf("id = %d\n", 2); printf("id = %d\n", 3);
 */
#define REPEAT_FROM_TO(from, to, macro, ...) \
    EXPAND(REPEAT_FROM_TO_IMPL(from, to, macro, __VA_ARGS__))

#define _REPEAT_FROM_TO_IMPL() REPEAT_FROM_TO_IMPL
#define REPEAT_FROM_TO_IMPL(from, to, macro, ...) \
    macro(from, __VA_ARGS__) \
    IF(NOT(EQ(from, to))) ( \
        /*
         * We need to defer recursive call twice here, one for REPEAT_FROM_TO_IMPL,
         * one for IF's arguments.
         * Also, we cannot use recursive macro directly. Here we use _REPEAT_FROM_TO
         * instead.
         */ \
        OBSTRUCT(_REPEAT_FROM_TO_IMPL)()(INC(from), to, macro, __VA_ARGS__) \
    )

/*
 * REPEAT_FROM_DOWNTO(start, end, M, ...):
 * Repeatedly expand macro M from start down to end. The first argument passed
 * to M will be the index. Possible variadic arguments will also be passed to M.
 *
 * Example:
 *     #define M(id, str) printf(str, id);
 *     REPEAT_FROM_DOWNTO(3, 1, M, "id = %d\n")
 * will generate:
 *     printf("id = %d\n", 3); printf("id = %d\n", 2); printf("id = %d\n", 1);
 */
#define REPEAT_FROM_DOWNTO(from, to, macro, ...) \
    EXPAND(REPEAT_FROM_DOWNTO_IMPL(from, to, macro, __VA_ARGS__))

#define _REPEAT_FROM_DOWNTO_IMPL() REPEAT_FROM_DOWNTO_IMPL
#define REPEAT_FROM_DOWNTO_IMPL(from, to, macro, ...) \
    macro(from, __VA_ARGS__) \
    IF(NOT(EQ(from, to))) ( \
        /*
         * We need to defer recursive call twice here, one for REPEAT_FROM_DOWNTO_IMPL,
         * one for IF's arguments.
         * Also, we cannot use recursive macro directly. Here we use _REPEAT_FROM_DONW_TO
         * instead.
         */ \
        OBSTRUCT(_REPEAT_FROM_DOWNTO_IMPL)()(DEC(from), to, macro, __VA_ARGS__) \
    )
