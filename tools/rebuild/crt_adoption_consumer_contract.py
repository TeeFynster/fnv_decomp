"""Pure metadata gate for a separately reviewed CRT diagnostic consumer.

No files, native processes, object parsing, image access or command execution.
The caller supplies actual observed complete selected fields and definitions.
Changing any pinned cohort metadata requires a new independently reviewed
successor contract, never relaxed matching of the current field identities.
"""
from __future__ import annotations
import hashlib
import json

import crt_provider_adoption_plan as planner

PLAN='2e3bde14db62d1db03dfd87386d68cdd9707f7c6d6bbea86ddf085795c13973f'
REVIEW='ecfd83f9f2b7d564e73e31361ff19759677f4b933689607e8d1d2f306d307cb5'
RESPONSE='aaec970cae1dcf32699bda75317afbbcd4551c67252fca0d508d47eec997024a'
COHORTS={
 'current_actual_V4':(37282,116,'d29570cb8144cbb6f0ec6fba4b17e27d3fce8f476538630918c079850f08d7fe'),
 'prospective_expanded_cohort':(44353,196,'08f5ee8fa735f164b9b49189dadbf2fb75b563a3b284583a0c13cedcd1753f20'),
}

def require(ok,message):
    if not ok:raise ValueError(message)

def bound_json(payload,expected,label):
    require(isinstance(payload,bytes) and hashlib.sha256(payload).hexdigest()==expected,
        label+' identity differs')
    return json.loads(payload)

def complete_fields(fields,count,digest):
    require(isinstance(fields,list) and len(fields)==count,'complete field count differs')
    require(planner.digest(sorted(fields,key=planner.canonical))==digest,
        'complete selected-field identity differs; new reviewed cohort required')

def binding_uses(bindings,fields,strong_definitions):
    require(isinstance(strong_definitions,(dict,set,list,tuple)), 'strong definitions must be explicit names')
    names=set(strong_definitions)
    require(len(bindings)==4 and len({x['canonical_undefined'] for x in bindings})==4,
        'not four distinct canonical aliases')
    expected={(base,role): (export,kind) for base,role,export,kind in planner.BINDINGS}
    require({(x['original_base'],x['role']) for x in bindings}==set(expected),
        'function/data role set differs')
    uses=[]
    for binding in bindings:
        base,role=binding['original_base'],binding['role']; export,kind=expected[(base,role)]
        canonical=planner.undefined(base,role)
        require(binding['canonical_undefined']==canonical and binding['normal_export']==export,
            'canonical or normal export differs')
        require(canonical not in names,'strong definition supersedes canonical alternate name')
        actual=planner.census(fields,base,role,kind)
        require(actual==binding['fields'] and len(actual)==binding['field_count'] and
            planner.digest(actual)==binding['field_census_sha256'],
            'complete per-canonical fields/source identities differ')
        uses.append(dict(canonical_undefined=canonical,normal_export=export,
            field_count=len(actual),field_census_sha256=planner.digest(actual)))
    return uses

def validate(plan_bytes,review_bytes,response_bytes,scope,fields,strong_definitions):
    """Return four reviewed tokens, not native permission or runtime approval.

    Native input observation completeness, source review, controlled normal
    library search and root's operation delegation remain caller obligations.
    `strong_definitions` must include every real selected strong definition,
    including data definitions, not merely the reported LINK error set.
    """
    require(scope in COHORTS,'unknown selected diagnostic scope')
    plan=bound_json(plan_bytes,PLAN,'plan');review=bound_json(review_bytes,REVIEW,'review')
    require(isinstance(response_bytes,bytes) and hashlib.sha256(response_bytes).hexdigest()==RESPONSE,
        'response identity differs')
    require(plan['kind']=='exact-normal-CRT-diagnostic-adoption-plan' and
        review['kind']=='application-crt-adoption-plan-artifact-review' and
        review['status']=='approved-for-separate-diagnostic-successor-preparation' and
        review['reviewer'] and review['plan_sha256']==PLAN and review['response_sha256']==RESPONSE,
        'review does not cover diagnostic plan')
    require(all(plan[k] is False for k in ('alias_applied','provider_adopted','runtime_ABI_approved','runtime_eligible')),
        'plan has incompatible runtime/adoption claims')
    count,alias_count,field_digest=COHORTS[scope]
    complete_fields(fields,count,field_digest)
    cohort=plan[scope];require(cohort['complete_input_fields']==count and
        cohort['binding_count']==4 and cohort['alias_field_count']==alias_count,'cohort scope differs')
    uses=binding_uses(cohort['bindings'],fields,strong_definitions)
    text=planner.response(cohort['bindings'])
    # Exact raw response bytes were hash-bound above. The reviewed Windows
    # writer emits CRLF; tokens returned to the caller have no line endings.
    require(text.splitlines()==response_bytes.decode('ascii').splitlines() and len(text.splitlines())==4 and
        sum(x['field_count'] for x in uses)==alias_count,'four reviewed response tokens differ')
    return dict(scope=scope,plan_sha256=PLAN,review_sha256=REVIEW,response_sha256=RESPONSE,
        tokens=text.splitlines(),validated_bindings=uses,complete_input_fields=count,
        alias_field_count=alias_count,selected_field_sha256=field_digest,
        native_operation_authorized=False,provider_adopted=False,runtime_ABI_approved=False,runtime_eligible=False,
        remaining='separate actual input/source freeze review and root diagnostic-only delegation')
